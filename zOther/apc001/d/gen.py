#!/usr/bin/env python

import random
from random import randrange 

N = 3
big = (1<<31) - 1

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    M = randrange(N)
    print(N, M)
    line(1, big, N)
    tree = [(randrange(j), j) for j in range(1, N)]
    forest = random.sample(tree, M);
    for (x,y) in forest:
        print(x, y)

main()

