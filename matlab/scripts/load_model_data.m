%% Clear
clear;
clc;

%% Paths
repoRoot = fileparts(fileparts(fileparts(which('load_model_data'))));
addpath(fullfile(repoRoot, 'matlab', 'HRIRS'), fullfile(repoRoot, 'matlab', 'models'));

%% Import to Simulink tdsp_data_container data type
Simulink.importExternalCTypes(fullfile(repoRoot, 'tdsp_data_container', 'tdsp_data_container.h'));

%% Build folder
Simulink.fileGenControl('set', ...
    'CodeGenFolder', fullfile(repoRoot, 'build', 'codegen'), ...
    'CacheFolder',   fullfile(repoRoot, 'build', 'cache'), ...
    'createDir', true);

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
