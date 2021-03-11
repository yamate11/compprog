#!/usr/bin/env python

import random
from random import randrange 

N = 5*10**4

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N)
    for j in range(N):
        line(-10**9, 10**9+1, 2)

main()

