#!/usr/bin/env python

import random
from random import randrange 

N = 100000

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N)
    lst = [randrange(1, 10) for _ in range(N)]
    print(' '.join(map(str,lst)))
    for k in range(N):
        t = randrange(2, N-1)
        s = lst[t-1] + lst[t] + lst[t+1]
        if s < 10**9:
            lst[t] = s
    print(' '.join(map(str,lst)))
        

main()

