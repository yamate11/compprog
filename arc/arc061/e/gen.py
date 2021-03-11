#!/usr/bin/env python

import random
from random import randrange 

N = 10
M = 10
aLim = 10
xLim = 30

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N, M)
    for j in range(M):
        p = randrange(1, N+1)
        q = randrange(1, N+1)
        c = randrange(1, M+1)
        print(p, q, c)

main()

