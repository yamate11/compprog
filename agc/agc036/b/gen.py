#!/usr/bin/env python3

import random
from random import randrange 

N = 7
K = 5
aLim = 6

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N, K)
    line(1, aLim, N)

main()

