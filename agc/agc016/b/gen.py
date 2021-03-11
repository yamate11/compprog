#!/usr/bin/env python

import random
from random import randrange 

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    N = 5
    print(N)
    line(1, N-1, N)

main()

