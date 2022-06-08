function f=model(t,y)
beta=0.2;%contact rate
gamma=0.083;%recovery rate
N=1000000;%population
f=[-beta/N*y(1)*y(2),beta/N*y(1)*y(2)-gamma*y(2),gamma*y(2)]';