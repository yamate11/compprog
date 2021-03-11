#!/usr/bin/env python3

def main():
    K, M = map(int, input().split())
    vecA = list(map(int, input().split())) + [0] * max(M-K, 0)
    vecC = list(map(int, input().split()))
    if M <= K:
        print(vecA[M-1])
    else:
        for p in range(K, M):
            x = 0
            for i in range(K):
                x ^= vecC[i] & vecA[p - i - 1]
            vecA[p] = x
        print(vecA[M-1])

main()
