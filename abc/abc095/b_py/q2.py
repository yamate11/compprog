#!/usr/bin/env python3

from sys import stdin

[n, x] = map(int, stdin.readline().split(' '))
ms = list(map(int, stdin))
print(n + (x - sum(ms)) // min(ms))

