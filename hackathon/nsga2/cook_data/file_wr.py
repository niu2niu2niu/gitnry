#!/usr/bin/python
#coding:utf8

import sys
from methods_traversal import methods_traversal

# 读当前需要调度的菜名
def read_dish_name(filename):
    d = {}
    with open(filename, 'r') as f:
        data = f.readlines()
        for line in data:
            if line[0] == '#':
                continue
            line = line.strip()
            d[line] = 1
    return d

# 读取资源列表
def read_machine_list(filename):
    d = {}
    d_unfold = {}
    count = 1
    with open(filename, 'r') as f:
        data = f.readlines()
        for line in data:
            line = line.strip()
            idx, name, num = line.split('\t')
            num = int(num)
            d[idx] = (name, num)
            d_unfold[idx] = []
            for i in range(num):
                d_unfold[idx].append(count + i)
            count += num
    return (d, d_unfold)

# 读取菜名和任务文件名的对应表
def read_dish_file_map(filename):
    d = {}
    with open(filename, 'r') as f:
        data = f.readlines()
        for line in data:
            line = line.strip()
            dish_name, file_name = line.split('\t')
            d[dish_name] = file_name
    return d

# 读取每个菜的任务文件
def read_dish_file(filename, d_unfold):
    d = {}
    with open(filename, 'r') as f:
        data = f.readlines()
        for line in data:
            line = line.strip()
            # text
            if line.count('\t') == 2:
                flag, step, text = line.split('\t')
                step = int(step.replace('step', ''))
                d[step] = {'text':text}
            # restraint
            if line.count('\t') == 1:
                flag, restraint = line.split('\t')
                step_high, step_low = restraint.split('>')
                step_high = int(step_high.replace('step', ''))
                step_low = int(step_low.replace('step', ''))
                if step_high in d:
                    if 'restraint' not in d[step_high]:
                        d[step_high]['restraint'] = [step_low]
                    else:
                        d[step_high]['restraint'].append(step_low)
            # machine and time
            if line.count('\t') == 3:
                flag, step, machine, time = line.split('\t')
                step = int(step.replace('step', ''))
                time = int(time.replace('time=', ''))
                d[step]['time'] = time
                machine = machine.replace('machine=', '')
                machine_l = machine.split(',')
                d[step]['machine'] = methods_traversal(d_unfold, machine_l)
    d_s = sorted(d.iteritems(), key=lambda d:d[0], reverse = True)
    return d

# 将已经汇总好的任务所有信息存入文件
def write_step_total(d_step_total):
    with open('output/restraint', 'w') as f_restraint:
        with open('output/text', 'w') as f_text:
            with open('output/method_time', 'w') as f_method_time:
                with open('output/machine', 'w') as f_machine:
                    f_text.write("# task_id task_text\n")
                    f_method_time.write("# task_id method_num task_time\n")
                    f_restraint.write("# task_id1 > task_id2\n")
                    f_machine.write("# task_id method_id machine_num machine_id1 machine_id2 ...\n")
                    for step in d_step_total:
                        # 任务优先级
                        for r in d_step_total[step]['restraint']:
                            restraint = str(step) + '\t' + str(r) + '\n'
                            f_restraint.write(restraint)
                        # 任务对应的文本
                        text = str(step) + '\t' + d_step_total[step]['text'] + '\n'
                        f_text.write(text)
                        # 任务方案个数和执行方案所需要的时间
                        machine_num = len(d_step_total[step]['machine'])
                        method_time = str(step) + '\t' + str(machine_num) + '\t' \
                                + str(d_step_total[step]['time']) + '\n'
                        f_method_time.write(method_time)
                        # 任务与 machine 的对应
                        for i in range(machine_num):
                            machine = str(step) + '\t' + str(i + 1) + '\t' 
                            # 当前方案的机器列表
                            method_machine_l = d_step_total[step]['machine'][i]
                            machine += str(len(method_machine_l)) + '\t'
                            for m in method_machine_l:
                                machine += str(m) + '\t'
                            machine = machine.strip('\t') + '\n'
                            f_machine.write(machine)
