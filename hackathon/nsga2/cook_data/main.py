#!/usr/bin/python
#coding:utf8

import sys
import read_file

if __name__ == '__main__':
    # 读取资源列表
    machine_list_filename = "machine_list.txt"
    d_machine_list = read_file.read_machine_list(machine_list_filename)
    print d_machine_list
    
    # 读当前需要调度的菜名
    dish_name_filename = "dish_name.txt"
    d_dish_name = read_file.read_dish_name(dish_name_filename)
    print d_dish_name

    # 读取菜名和任务文件名的对应表
    dish_file_map_filename = "dish_file_map.txt"
    d_dish_file_map = read_file.read_dish_file_map(dish_file_map_filename)
    print d_dish_file_map
