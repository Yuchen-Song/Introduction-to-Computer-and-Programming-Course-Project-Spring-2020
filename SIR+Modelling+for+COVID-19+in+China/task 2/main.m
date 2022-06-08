%Estimating Part
%para(1)=beta, para(2)=gamma, para(3)=S0
[para,y]=fminsearch(@obj,rand(1,2));

%Plotting Part
%load data
load China_culmulative_confirmed_case.txt;
C=China_culmulative_confirmed_case(:,2);
tspan=[1:1:100];%time span
%get integral
[t,y]=ode45(@(t,y) prediction(t,y,para),tspan,[96745,C(1,1),6]);
%the true initial condition should be S0, I0=34, R0=6
%plot the SIR model
hold;
grid on;
plot(t,y(:,1),'b',t,y(:,2),'r',t,y(:,3),'g');
title("SIR Model of Covid-19 in China");
xlabel("Days");
ylabel("Population");
%plot the confirmed cases curve
plot(t,y(:,2)+y(:,3),'c')
plot(t,C,'y');
legend("Susceptible","Infected","Recovered","Predicted","Confirmed");