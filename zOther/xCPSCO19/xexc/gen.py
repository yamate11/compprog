#!/usr/bin/env python

import random
from random import randrange 

N = 10
Q = 10
aLim = 10

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N, Q)
    for j in range(Q):
        com = randrange(2)
        if com == 0:
            x = randrange(N)
            y = randrange(aLim)
        else:
            x = randrange(N)
            y = randrange(x, N)
        print(com, x, y)

main()

