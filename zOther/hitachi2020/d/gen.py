#!/usr/bin/env python3

from random import randrange

def main():
    N = 2
    T = 5
    print(N, T)
    for i in range(N):
        print(randrange(5), randrange(5))

main()

