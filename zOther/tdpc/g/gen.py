#!/usr/bin/env python3

import random

def main():
    alph = 'abcdefghijklmnopqrstuvwxyz'
    N = 10**6
    s = ''
    for i in range(N):
        s += alph[random.randrange(26)]
        # s += alph[random.randrange(20,26)]
    print(s)
    K = random.randrange(1,10**18)
    print(K)

main()
