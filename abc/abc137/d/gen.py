#!/usr/bin/env python

import random
from random import randrange 

N = 10**5
M = 10**5

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N, M)
    for j in range(N):
        A = randrange(1, 10**5+1)
        B = randrange(1, 10**4+1)
        print(A, B)

main()

