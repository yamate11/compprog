#!/usr/bin/env python3

def solve():
    _dummy = input()
    A = [int(t) for t in input().split()]
    for a in A:
        if a == 0:
            return 0
    ans = 1
    for a in A:
        ans *= a
        if ans > 10**18:
            return -1
    return ans

def main():
    print(solve())

main()

        
