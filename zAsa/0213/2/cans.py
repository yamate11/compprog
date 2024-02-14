#!/usr/bin/env python3

N = int(input())
print(sum([(N - 1) / a for a in range(1, N + 1)]))
