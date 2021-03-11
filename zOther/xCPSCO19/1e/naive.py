#!/usr/bin/env python

def main():
    (N,Q) = map(int, input().split())
    A = list(map(int, input().split()))
    L = [0 for _ in range(Q)]
    R = [0 for _ in range(Q)]
    X = [0 for _ in range(Q)]
    for i in range(Q):
        (L[i], R[i], X[i]) = map(int, input().split())
    A.sort()
    for j in range(Q):
        axor = 0
        for i in range(N):
            if L[j] <= A[i] and A[i] <= R[j]:
                axor ^= A[i]
                A[i] = X[j]
        print(axor)
        A.sort()

main()
