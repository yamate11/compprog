#!/usr/bin/env python3

from itertools import product
result = [0, 1]
okay = 0
total = 0
n = 10
for res in product(result, repeat=n):
    total += 1
    for i in range(n - 2):
        if res[i:i+3] == (1, 1, 1):
            okay += 1
            break
print(okay/total) # 0.5078125
print(okay, total)
