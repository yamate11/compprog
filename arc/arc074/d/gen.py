#!/usr/bin/env python

import random
from random import randrange 

N = 3

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N)
    line(1, (1<<31) - 1, N*3)

main()

