#!/usr/bin/env python

import random
from random import randrange 

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    N = randrange(3, 10)
    A = randrange(0, 100)
    B = randrange(0, 100)
    C = randrange(0, 10)
    D = C + randrange(0, 4)
    print(N, A, B, C, D)

main()

