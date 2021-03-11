#!/usr/bin/env python

import random
from random import randrange 

# N = 3*10**5
N = 10
# Q = 2*10**5
Q = 5
# aLim = 2*10**8
aLim = 20
# xLim = 10**8
xLim = 20

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

