#!/usr/bin/env python3

import sys
import numpy as np

def main():
    N = int(input())
    A = np.array(input().split(), dtype=np.int32)
    B = np.array(input().split(), dtype=np.int32)
    ans = 0
    for k in range(4):
        mask = (1 << (k+1)) - 1
        C = A & mask
        D = B & mask
        C.sort()
        D.sort()
        print(C)
        print(D)

        # p, q, r = 0, 0, 0
        # for i in range(N-1, -1, -1):
        #     while p < N:
        #         if C[i] + D[p] >= 1 << k: break
        #         p += 1
        #     while q < N:
        #         if C[i] + D[q] >= 2 << k: break
        #         q += 1
        #     while r < N:
        #         if C[i] + D[r] >= 3 << k: break
        #         r += 1


        #     x = ((q - p) + (N - r)) % 2
        #     # print(p, q, r, x)
        #     ans = ans ^ (x << k)


    print(ans)

main()
