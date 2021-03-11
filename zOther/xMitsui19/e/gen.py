#!/usr/bin/env python

import random
from random import randrange 

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    N = randrange(1, 100001)
    print(N)
    v = [0, 0, 0]
    for i in range(N):
        x = randrange(3)
        print(v[x], end = ' ')
        v[x] += 1
    print()

main()

