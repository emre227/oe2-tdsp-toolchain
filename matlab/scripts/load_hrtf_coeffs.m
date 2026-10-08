%% Clear
clear;
clc;
%% Add HRIR paths
repoRoot = fileparts(fileparts(fileparts(which('load_hrtf_coeffs'))));
addpath(fullfile(repoRoot, 'matlab', 'HRIRS'), fullfile(repoRoot, 'matlab', 'models'));
%% Load Coeffs
%S = load("sil_HRIR-cipic_subject_162-200koeff-280_0.mat");
S1 = load("HRIR-cipic_subject_021-200koeff-80_0.mat");
S2 = load("HRIR-cipic_subject_021-200koeff-280_0.mat");
scaling = 0.5;

LEFT_SOURCE_HRIR_L = single(scaling * S1.hrirL);
LEFT_SOURCE_HRIR_R = single(scaling * S1.hrirR);

RIGHT_SOURCE_HRIR_L = single(scaling * S2.hrirL);
RIGHT_SOURCE_HRIR_R = single(scaling * S2.hrirR);

HRIR1 = [LEFT_SOURCE_HRIR_R(:) LEFT_SOURCE_HRIR_L(:)];
HRIR2 = [RIGHT_SOURCE_HRIR_R(:) RIGHT_SOURCE_HRIR_L(:)];
HRIR =  cat(3, HRIR1, HRIR2);
%% Testvektor

fs = 48000; %48 khz sampling
N = 1440;   % samples
t = (0:N-1)' / fs;
amplitude = 0.5;

f_sinus = 1000; % 1 khz sine wave freq
test_input =   int16(round(amplitude * 32767*sin(2*pi*t*f_sinus)));

%% sim both channels

mdl = 'hrtf_filter';
load_system(mdl);

ts = timeseries(test_input, t);
ts = setinterpmethod(ts, 'zoh');

for ch = 0:1
    tch = timeseries(uint8(ch*ones(N,1)), t);
    tch = setinterpmethod(tch, 'zoh');
    out = sim(mdl, 'LoadExternalInput','on', 'ExternalInput','ts, tch', ...
                   'StopTime', sprintf('%d/48000', N-1), ...
                   'SaveOutput','on', 'OutputSaveName','yout', 'SaveFormat','Dataset');
    y = int16(squeeze(out.yout{1}.Values.Data));
    if ch == 0, y_r = y(1:N); else, y_l = y(1:N); end
end

%% export header for iss
fid = fopen('test_vectors.h','w');
fprintf(fid,'/* 1 kHz Sinus, 0,5 FS, fs = 48 kHz, N = %d, Referenz aus %s */\n', N, mdl);
fprintf(fid,'#define N_TEST %d\n', N);
fprintf(fid,'static const int16_t test_in[N_TEST]    = {%s};\n', strjoin(string(test_input.'),','));
fprintf(fid,'static const int16_t test_ref_r[N_TEST] = {%s};\n', strjoin(string(y_r.'),','));
fprintf(fid,'static const int16_t test_ref_l[N_TEST] = {%s};\n', strjoin(string(y_l.'),','));

fclose(fid);
%% check
alt = load('ref_stufe_-1.mat');

isequal(y_l, alt.yL)
isequal(y_r, alt.yR)

%%
save('ref_stufe_3.mat',"y_r","y_l");