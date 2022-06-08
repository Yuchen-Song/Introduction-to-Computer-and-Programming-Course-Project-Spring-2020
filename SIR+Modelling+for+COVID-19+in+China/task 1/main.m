%task 1: Model a SIR model, with a time span of 200 days
tspan=[1,200];
[t,y]=ode113(@model,tspan,[999999,1,0]);
hold;
grid on;
plot(t,y(:,1),'b',t,y(:,2),'r',t,y(:,3),'g');
xlabel("Days");
ylabel("Population");
legend("Susceptible","Infected","Recovered");