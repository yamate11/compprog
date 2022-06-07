#!/usr/bin/env python3

import math

primeA = 10**9 + 7

def main():
    N = int(input())
    A = list(map(int, input().strip().split()))
    l = 1
    for i in range(N):
        g = math.gcd(l, A[i])
        l *= A[i] // g;
    ans = 0
    for i in range(N):
        ans += l // A[i] % primeA
        if ans >= primeA:
            ans -= primeA
    print(ans)

main()
