#!/usr/bin/env python

import random
from random import randrange 

N = 9

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    S = ''
    alph = 'abc'
    for i in range(N):
        S += alph[randrange(3)]
    print(S)

main()

