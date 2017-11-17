chri.t=[1,2,3,4,5,6];

% 测试用例
meth(1).r=[1,4];
meth(1).time=2;
meth(1).t_time=0;
meth(2).r=[2];
meth(2).time=3;
meth(2).t_time=0;
meth(3).r=[3];
meth(3).time=5;
meth(3).t_time=0;
meth(4).r=[4];
meth(4).time=22;
meth(4).t_time=2;
meth(5).r=[7];
meth(5).time=23;
meth(5).t_time=0;
meth(6).r=[1,4];
meth(6).time=7;
meth(6).t_time=24;

for i = 1:length(chri.t) %遍历所有任务
    word = num2str(chri.t(i));%将任务号转化为字符
    for k=1:length(meth(chri.t(i)).r) %遍历任务i所用到的资源
        hold on
        %设置坐标
        x1=meth(chri.t(i)).t_time;
        x4=x1;
        x2=x1 + meth(chri.t(i)).time;%x2，x3是该最大时间加上任务完成时间
        x3=x2;
        y1=meth(chri.t(i)).r(k)-0.5;%y1，y2是资源号减0.5
        y2=meth(chri.t(i)).r(k)-0.5;
        y3=meth(chri.t(i)).r(k);%y3，y4是资源号
        y4=meth(chri.t(i)).r(k);
        fill([x1,x2,x3,x4],[y1,y2,y3,y4],[0.05*chri.t(i)/2,1-0.05*chri.t(i)/2,0.05*chri.t(i)/2/2]);
        %对由[x1,x2,x3,x4],[y1,y2,y3,y4]围成的区域涂色
        text(0.5*x1+0.5*x2,0.5*y1+0.5*y4,word);%将任务号写在区域中间
    end
end
