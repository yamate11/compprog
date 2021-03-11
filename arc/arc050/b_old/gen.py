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
    R = randrange(1, 10**18);
    B = randrange(1, 10**18);
    # R = randrange(1, 10**9);
    # B = randrange(1, 10**9);
    x = randrange(2, 10**9);
    y = randrange(2, 10**9);
    print(R, B, x, y);

main()

