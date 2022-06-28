#!/usr/bin/env python3

N = int(input())
H = list(map(int, input().split())) + [0]
print(sum([max(H[i] - H[i + 1], 0) for i in range(N)]))

