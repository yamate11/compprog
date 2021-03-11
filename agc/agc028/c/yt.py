#!/usr/bin/env python3

import random

def main():
    n = 10**5
    print(n)
    for i in range(n):
        x = random.randrange(10**9)
        y = random.randrange(10**9)
        print(x,y)

main()
