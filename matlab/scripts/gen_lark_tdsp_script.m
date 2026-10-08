%% Generate Lark-tdsp.c from the tdsp_hw build
% Build tdsp_hw (Deploy) in Xplorer first, then copy output/Lark-tdsp.c into the firmware.

repo = fileparts(fileparts(fileparts(which('gen_lark_tdsp_script'))));
elfFile = fullfile(repo, 'tdsp', 'tdsp_hw', 'bin', 'hifi3z_lark_RI_2022_10', 'Deploy', 'tdsp_hw');
binFile = fullfile(repo, 'output', 'tdsp.bin');
outFile = fullfile(repo, 'output', 'Lark-tdsp.c');

% ELF -> binary image (base 0x5FFF0000)
status = system(sprintf('xt-objcopy -O binary "%s" "%s"', elfFile, binFile));
assert(status == 0, 'xt-objcopy failed');

fid = fopen(binFile, 'r');
bytes = fread(fid, inf, 'uint8');
fclose(fid);

% image must end before SRAM end (0x60037FFF), otherwise a segment is outside the RAM
assert(numel(bytes) <= hex2dec('48000'), 'tdsp.bin too large (%d bytes)', numel(bytes));

% pad to 32 bit, little endian
nWords = ceil(numel(bytes) / 4);
bytes(end+1 : nWords*4) = 0;
words = typecast(uint8(bytes), 'uint32');

fid = fopen(outFile, 'w');
fprintf(fid, '/* TDSP program image, generated from tdsp.bin. Do not edit. */\n');
fprintf(fid, '#include <stdint.h>\n\n');
fprintf(fid, '/* target address 0x5FFF0000, %d words */\n', nWords);
fprintf(fid, 'const uint32_t tdsp_image[%d] = {\n', nWords);
for i = 1:8:nWords
    fprintf(fid, '    ');
    fprintf(fid, '0x%08X, ', words(i:min(i+7, nWords)));
    fprintf(fid, '\n');
end
fprintf(fid, '};\n');
fclose(fid);

fprintf('Generated %s (%d bytes)\n', outFile, numel(bytes));