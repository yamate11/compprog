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
    N = randrange(1,5)
    print(N)
    for i in range(N):
        print(randrange(10), end = ' ')
    print()
    Q = 1
    print(Q)
    t = randrange(1, 4)
    if t == 1:
        print(1, randrange(1, N+1), randrange(20))
    else:
        print(t, randrange(20))

main()

