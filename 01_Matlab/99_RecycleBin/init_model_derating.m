

Ts_ctrl = 6e-5;         % [s] Controller samplid time (~16 kHz)
% Ts_ctrl = 12e-5;        % [s] Controller samplid time (~8 kHz)
f_ctrl          = 1/Ts_ctrl;    % [Hz] Controller frequency = 1/Ts_ctrl

%% Motor Current Derating Parameters
PWM_LIM_MAX = 1000;
t_DC_CUR_DER = 2000;    % [ms]
t_DC_CUR_REC = 2000;
DC_CUR_LIM_CONT = 15;
DC_CUR_LIM_PEAK = 20;

dt_curLimDer = PWM_LIM_MAX / t_DC_CUR_DER / (f_ctrl / 1000);
dt_curLimRec = - PWM_LIM_MAX / t_DC_CUR_REC / (f_ctrl / 1000);