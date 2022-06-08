function f=prediction(t,y,para)
N=96745;%para(3)+40;%population
f=[-para(1)/N*y(1)*y(2),para(1)/N*y(1)*y(2)-para(2)*y(2),para(2)*y(2)]';