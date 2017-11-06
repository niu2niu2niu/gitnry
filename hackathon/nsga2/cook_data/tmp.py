#!/usr/bin/python
#coding=utf8

V = 6
test = [i+1 for i in range(V)]
print 'test:', test
print 'V:', V

meth = [{'m':[], 'r':[], 'time':[]}]
for i in range(1, V+1):
    meth.append({'m':[], 'r':[], 'time':[]})
meth[1]['m']=[1,2,3];#比如测试任务1的方案meth，成员m表示方案编号
meth[1]['r']=[(1,4),(3,5),(6,8)];#成员r表示对应方案需要用到的仪器（数组），不同方案的仪器组成矩阵
meth[1]['time']=[2,5,3];#成员time表示对应方案需要用到的时间
meth[2]['m']=[1,2,3,4];
meth[2]['r']=[(2),(4),(6),(7)];
meth[2]['time']=[3,4,3,4];
meth[3]['m']=[1,2];
meth[3]['r']=[(3),(5)];
meth[3]['time']=[5,5];
meth[4]['m']=[1,2];
meth[4]['r']=[(4),(8)];
meth[4]['time']=[22,20];
meth[5]['m']=[1];
meth[5]['r']=[(7)];
meth[5]['time']=[23];
meth[6]['m']=[1,2,3];
meth[6]['r']=[(1,4),(3,7),(6,8)];
meth[6]['time']=[7,8,8];
print 'meth:', meth

meth_length = [0 for i in range(V)];#meth_length中记录该任务序列下的方案
for i in range(V):
    meth_length[i] = len(meth[test[i]]['m'])
print 'meth_length:', meth_length

choose_num = 1
for i in range(V):
    choose_num *= meth_length[i]
print 'choose_num:', choose_num

methods = [[1 for col in range(V)] for row in range(choose_num)] #可选方案组合记录在methods矩阵中
for meth_i in range(choose_num): #从0到方案组合总数减1遍历
    factor = choose_num;#设置进制因子
    methods_i = meth_i;#保存除数
    for meth_j in range(1, V): #除V-1个进制因子
        factor = factor / meth_length[meth_j];#每次修正进制因子
        methods[meth_i][meth_j-1] = (methods_i/(factor))+1;#methods的每位是商的值加1
        remain = methods_i % factor;#记录余数
        methods_i = remain;#修正除数为本次的余数
    methods[meth_i][V-1] = remain + 1;#第V位是余数加1
print 'methods:', methods
