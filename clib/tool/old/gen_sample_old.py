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
    print(N, Q)
    line(0, aLim, N)
    for j in range(Q):
        L = randrange(xLim)
        R = L + randrange(xLim)
        X = randrange(2*xLim)
        print(L, R, X)

main()

