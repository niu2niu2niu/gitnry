#!/usr/bin/python
#coding:utf8

import sys

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
    with open(filename, 'r') as f:
        data = f.readlines()
        for line in data:
            line = line.strip()
            idx, name, num = line.split('\t')
            d[idx] = (name, num)
    return d

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

