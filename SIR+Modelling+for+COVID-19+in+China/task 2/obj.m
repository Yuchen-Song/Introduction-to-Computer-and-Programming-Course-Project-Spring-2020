function f=obj(para)
%f equals to the sum of the squre of each difference between Ct and modeled Ct
%we use the data from 1/11/2020 to 2/29/2020(50 days)
%the data is the confirmed case of China
%the prediction span is 1/11/2020 to 4/19/2020(100 days)
f=0;%initialization of f
tspan=[1:1:50];%time span
%load data
load China_culmulative_confirmed_case.txt;
C=China_culmulative_confirmed_case(:,2);
%get the integral
[t,y]=ode45(@(t,y) prediction(t,y,para),tspan,[96745,C(1,1),6]);
%the initial condition should be S0, I0=34, R0=6
for i=1:50
    f=f+(C(i,1)-y(i,2)-y(i,3))^2;
end
