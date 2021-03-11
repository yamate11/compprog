#!/usr/bin/env python3

import random

def main():
    n = 10**6
    q = 75
    oa = ord('A')
    s = [random.choice('DMCX') for i in range(n)]
    ks = [str(random.randrange(1,n)) for i in range(q)]
    print(n)
    print(''.join(s))
    print(q)
    print(' '.join(ks))

main()
