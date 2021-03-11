#!/usr/bin/env python3

def check(n, B, l, r, C, D):
    if n == 1:
        return l <= B and B <= r
    return check(n-1, B, l-D, r-C, C, D) or check(n-1, B, l+C, r+D, C, D)

def main():
    (N, A, B, C, D) = map(int, input().strip().split())
    if check(N, B, A, A, C, D):
        print("YES")
    else:
        print("NO")

main()
