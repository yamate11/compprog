#!/usr/bin/env python3

from math import sqrt
import sys

def main():
    A, B = map(int, input().split())
    C = 1
    for i in range(B):
        C *= A
    prod = 1
    for d in range(1, C + 1):
        if C % d == 0:
            prod *= d
    print(f"prod={prod}", file=sys.stderr)
    ans = 0
    while (prod % A == 0):
        prod = prod // A
        ans += 1
    print(ans)
            

    

main()
