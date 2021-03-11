#!/usr/bin/env python

import random
from random import randrange 

N = 7
Q = 5
aLim = 10
xLim = 30

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    N = 4
    a = [randrange(1,4) for _ in range(N)]
    s = sum(a)
    K = randrange(0, s+1)
    print(N, K)
    for x in a:
        print(int(x))

main()

