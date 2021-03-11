#!/usr/bin/env python3

from itertools import permutations

def main():
    global N, T
    N, T = map(int,(input().split()))
    vecA = [0] * N;
    vecB = [0] * N;
    for i in range(N):
        vecA[i], vecB[i] = map(int,(input().split()))
    vmax = 0
    for perm in permutations(range(N)):
        t = 0
        cnt = 0
        for i in perm:
            t += 1
            wait = vecA[i] * t + vecB[i]
            t += wait
            if t > T:
                break
            cnt += 1
        vmax = max(vmax, cnt)
    print(vmax)

main()


