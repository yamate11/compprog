#!/usr/bin/env python3

from random import randrange
import sys

def decode(x):
    return chr(ord('a') + x - 26) if x >= 26 else chr(ord('A') + x)

def main():
    t = 1000
    N = 90000 // t;
    print(N)
    for i in range(N):
        lst = [randrange(0,52) for j in range(t)]
        # print(lst)
        print(''.join([decode(x) for x in lst]))

main()
