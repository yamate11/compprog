#!/usr/bin/env python3

vInit = (1<<31) - 1

def main():
    (N, Q) = map(int, input().split())
    A = [vInit for _ in range(N)]
    for _ in range(Q):
        lst = list(map(int, input().split()))
        if lst[0] == 0:
            (i, j, x) = lst[1:]
            for k in range(i, j+1):
                A[k] = x
        else:
            (i, j) = lst[1:]
            v = min(A[i : j+1])
            print(v)

main()
