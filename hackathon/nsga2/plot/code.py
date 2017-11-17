#!/usr/bin/python
#coding=utf8

import sys

if __name__ == '__main__':
    f = open('../output/task_pop.out', 'r')
    data = f.readlines()
    f.close()
    line = data[0]
    line = line.strip()
    line = line.strip(',')
    obj1, obj2, results = line.split('\t')
    res_l = results.split(',')
    for i in range(len(res_l)):
        res_l[i] = res_l[i].strip('(')
        res_l[i] = res_l[i].strip(')')
        res_i_d = {}
        for item in res_l[i].split(' '):
            key, value = item.split(':')
            if key == 'r':
                if key not in res_i_d:
                    res_i_d[key] = [value]
                else:
                    res_i_d[key].append(value)
            else:
                res_i_d[key] = value
        res_l[i] = res_i_d
    #print res_l
    # 打印任务序列
    p_line = 'chri.t=['
    for item in res_l:
        p_line += item['t'] + ','
    p_line = p_line.strip(',')
    p_line += '];'
    print p_line
    print

    # 打印调度信息
    #meth(1).r=[1,4];
    #meth(1).time=2;
    #meth(1).t_time=0;
    for item in res_l:
        p_line = 'meth(%s).time=%s;' %(item['t'], item['time'])
        print p_line
        p_line = 'meth(%s).t_time=%s;' %(item['t'], item['t_time'])
        print p_line
        p_line = 'meth(%s).r=[' %(item['t'])
        for r in item['r']:
            p_line += r + ','
        p_line = p_line.strip(',')
        p_line += '];'
        print p_line
