#!/usr/bin/env python

import random
from random import randrange 

def main():
    N = randrange(1, 100000)
    X = randrange(1,10)
    # X = randrange(-10**8, 10**8)
    D = randrange(1,2)
    # D = randrange(-10**8, 10**8)
    print(N, X, D)

main()

