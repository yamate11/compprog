#!/usr/bin/env python3

def solve():
    s = input().strip()
    lo = int(s)
    lo2 = lo * lo
    hi2 = (lo + 1) * (lo + 1)
    for i in range(len(s), -1, -1):
        th = 100 ** i
        p = lo2 // th;
        if lo2 <= th * p < hi2:
            return p
        if lo2 <= th * (p+1) < hi2:
            return p+1

def main():
    print(solve())

main()
