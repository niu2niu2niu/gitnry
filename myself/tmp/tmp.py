import os,sys

#s = int(raw_input())
#if s%3==0:
#    result = long('21'*(s/3))
#elif s%3==1:
#    result = long('12'*(s/3)+'1')
#else:
#    result = long('21'*(s/3)+'2')
#print result

#n = int(raw_input())
#b = n/3
#a = n%3
#str = '21'*b
#if a==0:
#    print int(str)
#elif a==1:
#    print int('1'+str)
#else:
#    print int(str+'2')

#import numpy as np
#import pandas as pd

#if __name__ == "__main__":
#    a = input()
#    m = int(a/3)
#    n = int(a%3)
#    x=0
#    for i in range(m):
#        x =x+21*10^(i+1)
#    if n == 0:
#        print x
#    elif n == 1:
#        x = x+10^2(i+1)
#        print x
#    else :
#        x = x+2
#        print x

if __name__ == "__main__":
    line = sys.stdin.readline().strip()
    ori = int(line)

    for a in range(1,3):
        s=ori
        ans=''
        while s>0:
            ans=str(a)+ans
            s-=a
            if a==1:
                a=2
            else:
                a=1
        if s==0:
            break
    print ans
