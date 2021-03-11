#!/usr/bin/env python3

from random import randrange

def main():
    K = randrange(1, 6)
    M = randrange(1, 11)
    vecA = [randrange(32) for k in range(K)]
    vecC = [randrange(32) for k in range(K)]
    print(K, M)
    print(' '.join(map(str, vecA)))
    print(' '.join(map(str, vecC)))

main()
