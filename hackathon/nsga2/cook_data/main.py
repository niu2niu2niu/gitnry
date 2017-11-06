#!/usr/bin/python
#coding:utf8

import sys
import read_file

def step_total(d_step_info, d_step_total):
    length = len(d_step_total)
    for step_info in d_step_info:
        new_idx = step_info + length
        d_step_total[new_idx] = d_step_info[step_info]
        if 'restraint' not in d_step_total[new_idx]:
            d_step_total[new_idx]['restraint'] = []
        for i in range(len(d_step_total[new_idx]['restraint'])):
            d_step_total[new_idx]['restraint'][i] += length

if __name__ == '__main__':
    # 读取资源列表
    machine_list_filename = "machine_list.txt"
    (d_machine_list, d_machine_list_unfold) = read_file.read_machine_list(machine_list_filename)
    print 'd_machine_list:', d_machine_list
    print 'd_machine_list_unfold:', d_machine_list_unfold
    
    # 读当前需要调度的菜名
    dish_name_filename = "dish_name.txt"
    d_dish_name = read_file.read_dish_name(dish_name_filename)
    print 'd_dish_name:', d_dish_name

    # 读取菜名和任务文件名的对应表
    dish_file_map_filename = "dish_file_map.txt"
    d_dish_file_map = read_file.read_dish_file_map(dish_file_map_filename)
    print 'd_dish_file_map:', d_dish_file_map

    # 根据每个菜对应的文件读取任务信息
    d_step_total = {}
    for dish_name in d_dish_name:
        dish_filename = d_dish_file_map[dish_name]
        print 'dish_filename:', dish_filename
        d_step_info = read_file.read_dish_file(dish_filename)
        print 'd_step_info:', d_step_info
        step_total(d_step_info, d_step_total)
        #print 'd_step_total', d_step_total
