%% Generate Lark-tdsp.c from tdsp.bin
binFile   = 'tdsp.bin';
outFile   = 'Lark-tdsp.c';
arrayName = 'tdsp_image';
maxBytes  = hex2dec('48000');           % DRAM0 start to SRAM end (0x5FFF0000-0x60037FFF)

% Read binary image
binId = fopen(binFile, 'r');
assert(binId ~= -1, '%s not found', binFile);
imageBytes = fread(binId, inf, 'uint8');
fclose(binId);

assert(numel(imageBytes) <= maxBytes, ...
       '%s too large (%d bytes): segment outside 0x5FFF0000-0x60037FFF?', binFile, numel(imageBytes));

% Pad to word boundary, convert to 32-bit words (little endian)
numWords = ceil(numel(imageBytes) / 4);
imageBytes(end+1 : numWords*4) = 0;
imageWords = typecast(uint8(imageBytes), 'uint32');

% Write C file
outId = fopen(outFile, 'w');
fprintf(outId, '/* TDSP program image, generated from %s. Do not edit. */\n', binFile);
fprintf(outId, '#include <stdint.h>\n\n');
fprintf(outId, '/* Target address 0x5FFF0000, %d words */\n', numWords);
fprintf(outId, 'const uint32_t %s[%d] = {\n', arrayName, numWords);

wordsPerLine = 8;
for first = 1 : wordsPerLine : numWords
    last = min(first + wordsPerLine - 1, numWords);
    fprintf(outId, '    ');
    fprintf(outId, '0x%08X, ', imageWords(first:last));
    fprintf(outId, '\n');
end

fprintf(outId, '};\n');
fclose(outId);
disp(['Generated ' outFile]);