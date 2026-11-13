%% Clear
clear;
clc;

%% Paths
repoRoot = fileparts(fileparts(fileparts(which('load_model_data'))));
addpath(fullfile(repoRoot, 'matlab', 'HRIRS'), fullfile(repoRoot, 'matlab', 'models'));

%% Import to Simulink tdsp_data_container data type
Simulink.importExternalCTypes(fullfile(repoRoot, 'tdsp_data_container', 'tdsp_data_container.h'));
%% Copy Config
cs = copy(getActiveConfigSet('tdsp_model_wrapper'));
attachConfigSet('HRTF_IIR_Baris_FixedPoint_v2', cs, true);
setActiveConfigSet('HRTF_IIR_Baris_FixedPoint_v2', cs.Name);
%% Build folder
Simulink.fileGenControl('set', ...
    'CodeGenFolder', fullfile(repoRoot, 'build', 'codegen'), ...
    'CacheFolder',   fullfile(repoRoot, 'build', 'cache'), ...
    'createDir', true);
%% Load Coeffs IIR
S = load("koeff_parameter_iir_16");

ALPHA = transpose([S.Alpha(2,:) ; S.Alpha(1,:)]);
BETA  = transpose([S.Beta(2,:) ; S.Beta(1,:)]);
DELAY = [S.Delay(2) S.Delay(1)];
GAIN  = [ S.Gain(2)  S.Gain(1)];

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
%% Simulation parameters (fixedpoint designer)
T_ch  = 2; %s
T_sim = 2*T_ch; %s


%%
mdl = 'HRTF_IIR_BARIS_FixedPointv2';
load_system(mdl);
set_param(mdl,'DataTypeOverride','Double');