#!/usr/bin/env python3
#-------------------------------------------------------------

N = int(input())
H = [int(input()) for _ in range(N)]
B = [0] + \
    [i for i in range(1, N - 1)
       if H[i - 1] > H[i] and H[i] < H[i + 1]] + \
    [N - 1]
print(max([B[i + 1] - B[i] + 1 for i in range(len(B) - 1)]))



