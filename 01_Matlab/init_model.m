
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This file is part of the hoverboard-new-firmware-hack project
% Compared to previouse commutation method, this project offers
% 3 more additional control method for BLDC motors.
% The new control methods offers superior performanace 
% compared to previous method featuring:
% >> reduced noise and vibrations
% >> smooth torque output
% >> improved motor efficiency -> lower energy consumption
% 
% Author: Emanuel FERU
% Copyright © 2019 Emanuel FERU <aerdronix@gmail.com>
%
% This program is free software: you can redistribute it and/or modify
% it under the terms of the GNU General Public License as published by
% the Free Software Foundation, either version 3 of the License, or
% (at your option) any later version.
%
% This program is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details.
%
% You should have received a copy of the GNU General Public License
% along with this program.  If not, see <http://www.gnu.org/licenses/>.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Clear workspace
close all
clear
clc

% Load model parameters
load BLDCmotorControl_data;
Ts      = 5e-6;         % [s] Model samplind time (200 kHz)
Ts_ctrl = 6e-5;         % [s] Controller samplid time (~16 kHz)
% Ts_ctrl = 12e-5;        % [s] Controller samplid time (~8 kHz)

% BLDC control parameters
CTRL_COMM       = 0;    % Commutation
CTRL_TRAP       = 1;    % Pure Trapezoidal
CTRL_SIN        = 2;    % Sinusoidal
CTRL_SIN3       = 3;    % Sinusoidal 3rd armonic

z_ctrlTypSel    = CTRL_SIN3;    % Control method selection

% Motor Parameters
n_polePairs     = 15;   % [-] Number of pole pairs
a_elecPeriod    = 360;  % [deg] Electrical angle period
a_elecAngle     = 60;   % [deg] Electrical angle between two Hall sensor changing events
a_mechAngle     = a_elecAngle / n_polePairs;    % [deg] Mechanical angle

%% F01_Preliminary_Calculations

% Position Calculation Parameters
% Hall          = 4*hA + 2*hB + hC
% Hall          = [0 1 2 3 4 5 6 7]
vec_hallToPos   = [0 5 3 4 1 0 2 0];  % [-] Mapping Hall signal to position

% Speed Calculation Parameters
f_ctrl          = 1/Ts_ctrl;    % [Hz] Controller frequency = 1/Ts_ctrl
cf_speedCoef    = round(f_ctrl * a_mechAngle * (pi/180) * (30/pi));     % [-] Speed calculation coefficient (factors are due to conversions rpm <-> rad/s)
cf_speedFilt    = 10;       % [%] Speed filter in percent [1, 100]. Lower values mean softer filter
z_maxCntRst     = 1500;     % [-] Maximum counter value for reset (works also as time-out to detect standing still)
r_commDCDeacv   = 70;       % [-] Commutation method deactivation Duty Cycle threshold (arbitrary small number)
n_commDeacvHi   = 30;       % [rpm] Commutation method deactivation speed high
n_commAcvLo     = 15;       % [rpm] Commutation method activation speed low
dz_counterHi    = 50;       % [-] Counter gradient High. Above this value the control resets to Commudation method (to deal with the high dynamics)
dz_counterLo    = 20;       % [-] Counter gradient Low. Below this value the control authorizes the Advance method (high dynamics have passed)

%% F02_Electrical_Angle_Calculation
b_phaAdvEna     = 1;    % [-] Phase advance enable parameter: 0 = disable, 1 = enable

% The map below was experimentaly calibrated on the real motor. Objectives: minimum noise and minimum torque ripple
a_phaAdv_M1     = [0   0   0   0   0   2   3   5   9  16   25];     % [deg] Phase advance angle
r_phaAdvDC_XA   = [0 100 200 300 400 500 600 700 800 900 1000];     % [-] Phase advance Duty Cycle grid
% plot(r_phaAdvDC_XA, a_phaAdv_M1);

%% F03_Speed_Control
sca_factor      = 1000;     % [-] scalling factor (to avoid truncation approximations on integer data type)

% Commutation method
z_commutMap_M1  = sca_factor*[ 1  1  0 -1 -1  0;    % Phase A
                              -1  0  1  1  0 -1 ;   % Phase B
                               0 -1 -1  0  1  1];   % Phase C  [-] Commutation method map

% Trapezoidal method
a_trapElecAngle_XA  = [0 60 120 180 240 300 360];  % [deg] Electrical angle grid
r_trapPhaA_M1       = sca_factor*[ 1  1  1 -1 -1 -1  1];
r_trapPhaB_M1       = sca_factor*[-1 -1  1  1  1 -1 -1];
r_trapPhaC_M1       = sca_factor*[ 1 -1 -1 -1  1  1  1];

% Sinusoidal method
a_sinElecAngle_XA   = 0:10:360;
omega               = a_sinElecAngle_XA*(pi/180);
pha_adv             = 30;       % [deg] Phase advance to mach commands with the Hall position
r_sinPhaA_M1        = sin(omega + pha_adv*(pi/180));
r_sinPhaB_M1        = sin(omega - 120*(pi/180) + pha_adv*(pi/180));
r_sinPhaC_M1        = sin(omega + 120*(pi/180) + pha_adv*(pi/180));

% Sinusoidal 3rd armonic method
A                   = 1.15;     % Sine amplitude (tunable to get the Saddle sin maximum to value 1000)
sin3Arm             = 0.22*sin(3*(omega + pha_adv*(pi/180)));     % 3rd armonic
r_sin3PhaA_M1       = sin3Arm + A*r_sinPhaA_M1;
r_sin3PhaB_M1       = sin3Arm + A*r_sinPhaB_M1;
r_sin3PhaC_M1       = sin3Arm + A*r_sinPhaC_M1;

% Rounding for representation on integer data type
r_sinPhaA_M1        = round(sca_factor * r_sinPhaA_M1);
r_sinPhaB_M1        = round(sca_factor * r_sinPhaB_M1);
r_sinPhaC_M1        = round(sca_factor * r_sinPhaC_M1);
r_sin3PhaA_M1       = round(sca_factor * r_sin3PhaA_M1);
r_sin3PhaB_M1       = round(sca_factor * r_sin3PhaB_M1);
r_sin3PhaC_M1       = round(sca_factor * r_sin3PhaC_M1);

disp('---- BLDC_controller: Initialization OK ----');

%% Plot control methods

show_fig = 0;
if show_fig
    
    hall_A = [1 1 1 0 0 0 0] + 4;
    hall_B = [0 0 1 1 1 0 0] + 2;
    hall_C = [1 0 0 0 1 1 1];
    
    color = ['m' 'g' 'b'];
    lw = 1.5;
    figure
    s1 = subplot(321); hold on
    stairs(a_trapElecAngle_XA, hall_A, color(1), 'Linewidth', lw);
    stairs(a_trapElecAngle_XA, hall_B, color(2), 'Linewidth', lw);
    stairs(a_trapElecAngle_XA, hall_C, color(3), 'Linewidth', lw);
    xticks(a_trapElecAngle_XA);
    grid
    yticks(0:5);
    yticklabels({'0','1','0','1','0','1'});
    title('Hall sensors');
    legend('Phase A','Phase B','Phase C','Location','NorthWest');
    
    s2 = subplot(322); hold on
    stairs(a_trapElecAngle_XA, hall_A, color(1), 'Linewidth', lw);
    stairs(a_trapElecAngle_XA, hall_B, color(2), 'Linewidth', lw);
    stairs(a_trapElecAngle_XA, hall_C, color(3), 'Linewidth', lw);
    xticks(a_trapElecAngle_XA);
    grid
    yticks(0:5);
    yticklabels({'0','1','0','1','0','1'});
    title('Hall sensors');
    legend('Phase A','Phase B','Phase C','Location','NorthWest');
    
    s3 = subplot(323); hold on
    stairs(a_trapElecAngle_XA, [z_commutMap_M1(1,:) z_commutMap_M1(1,end)] + 6000, color(1), 'Linewidth', lw);
    stairs(a_trapElecAngle_XA, [z_commutMap_M1(2,:) z_commutMap_M1(1,end)] + 3000, color(2), 'Linewidth', lw);
    stairs(a_trapElecAngle_XA, [z_commutMap_M1(3,:) z_commutMap_M1(1,end)], color(3), 'Linewidth', lw);
    xticks(a_trapElecAngle_XA);
    yticks(-1000:1000:7000);
    yticklabels({'-1000','0','1000','-1000','0','1000','-1000','0','1000'});
    ylim([-1000 7000]);
    grid
    title('Commutation method [0]');
    
    s5 = subplot(325); hold on
    plot(a_trapElecAngle_XA, r_trapPhaA_M1, color(1), 'Linewidth', lw);
    plot(a_trapElecAngle_XA, r_trapPhaB_M1, color(2), 'Linewidth', lw);
    plot(a_trapElecAngle_XA, r_trapPhaC_M1, color(3), 'Linewidth', lw);
    xticks(a_trapElecAngle_XA);
    grid
    title('Pure trapezoidal method [1]');
    xlabel('Electrical angle [deg]');
    
    s4 = subplot(324); hold on
    plot(a_sinElecAngle_XA, r_sinPhaA_M1, color(1), 'Linewidth', lw);
    plot(a_sinElecAngle_XA, r_sinPhaB_M1, color(2), 'Linewidth', lw);
    plot(a_sinElecAngle_XA, r_sinPhaC_M1, color(3), 'Linewidth', lw);
    xticks(a_trapElecAngle_XA);
    grid
    title('Sinusoidal method [2]');
    
    s6 = subplot(326); hold on
    plot(a_sinElecAngle_XA, r_sin3PhaA_M1, color(1), 'Linewidth', lw);
    plot(a_sinElecAngle_XA, r_sin3PhaB_M1, color(2), 'Linewidth', lw);
    plot(a_sinElecAngle_XA, r_sin3PhaC_M1, color(3), 'Linewidth', lw);
    xticks(a_trapElecAngle_XA);
    grid
    title('Sinusoidal 3rd armonic [3]');
    xlabel('Electrical angle [deg]');
    linkaxes([s1 s2 s3 s4 s5 s6],'x');
    xlim([0 360]);
end
