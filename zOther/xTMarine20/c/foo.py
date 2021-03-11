#!/usr/bin/env python3

def main():
    N,K = map(int, input().strip().split())
    A = list(map(int, input().strip().split()))
    for i in range(10):
        vec = [0] * N
        for j in range(N):
            for d in range(-A[j], A[j] + 1):
                z = j + d
                if z < 0 or N <= z:
                    continue
                vec[z] += 1
        for j in range(N):
            A[j] = vec[j]
        print(A)
             

main()
