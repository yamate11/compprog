#!/usr/bin/env python3

vInit = (1<<31) - 1

def main():
    (N, Q) = map(int, input().split())
    A = [vInit for _ in range(N)]
    for _ in range(Q):
        (com, x, y) = map(int, input().split())
        if com == 0:
            A[x] = y
        else:
            v = min(A[x : y+1])
            print(v)

main()
