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
    M = randrange(1, N*N+1)
    print(N, M)
    for i in range(N):
        e = " " if i < N-1 else "\n";
        print(randrange(1, 5), end=e)

main()

