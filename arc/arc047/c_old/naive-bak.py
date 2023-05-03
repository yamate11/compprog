#!/usr/bin/env python3

import itertools

def fact(n):
    if n == 0: return 1
    return fact(n-1) * n

def main():
    (N, K) = map(int, input().split())
    p = itertools.permutations(range(1, N+1))
    print("\n".join(map(str,list(p)[fact(N) // K - 1])))

main()
