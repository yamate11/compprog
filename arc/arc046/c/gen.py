#!/usr/bin/env python3

import random

def main():
    N = random.randrange(1,4)
    M = random.randrange(1,4)
    print(N, M)
    for i in range(N+M):
        a = random.randrange(1,10)
        b = random.randrange(1,10)
        print(a, b)

main()
