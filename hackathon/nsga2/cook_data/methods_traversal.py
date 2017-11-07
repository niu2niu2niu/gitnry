#!/usr/bin/python
#coding=utf8

def methods_traversal(d, array):
    V = len(array)
#    print 'V:', V
    meth_length = [0 for i in range(V)];
    for i in range(V):
        meth_length[i] = len(d[array[i]])
#    print 'meth_length:', meth_length
    
    choose_num = 1
    for i in range(V):
        choose_num *= meth_length[i]
#    print 'choose_num:', choose_num
    
    methods = [[1 for col in range(V)] for row in range(choose_num)]
    for meth_i in range(choose_num):
        factor = choose_num;
#        print 'factor:', factor
        methods_i = meth_i;
#        print 'methods_i:', methods_i
        for meth_j in range(1, V):
            factor = factor / meth_length[meth_j-1];
#            print ' factor:', factor
            methods[meth_i][meth_j-1] = d[array[meth_j-1]][(methods_i/(factor))];
            remain = methods_i % factor;
            methods_i = remain;
#            print ' methods_i:', methods_i
        methods[meth_i][V-1] = d[array[V-1]][remain];
#    print 'methods:', methods
    return methods

if __name__ == "__main__":
    d_machine_list_unfold = {'1': [1, 2], '3': [4], '2': [3], '5': [7, 8], '4': [5, 6], '7': [10], '6': [9], '8': [11, 12, 13, 14, 15]}
#    print 'd_machine_list_unfold:', d_machine_list_unfold
    machine_str = "machine=1,2"
    machine_str = machine_str.replace('machine=', '')
    machine_l = machine_str.split(',')
    methods = methods_traversal(d_machine_list_unfold, machine_l)
    print methods
