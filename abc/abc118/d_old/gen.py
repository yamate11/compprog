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
    N = randrange(10,20)
    M = randrange(1, 10)
    ss = list(map(str,range(1, 10)))
    random.shuffle(ss)
    print(N, M)
    print(' '.join(ss[:M]))

main()

