#!/usr/bin/env python

import random
from random import randrange 

N = 10
M = 5
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
        L = randrange(1, N)
        R = L + randrange(1, N-L+1)
        C = randrange(xLim)
        print(L, R, C)

main()

