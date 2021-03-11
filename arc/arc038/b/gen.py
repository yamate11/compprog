#!/usr/bin/env python3

import random

N = 6
p = 0.3

H = random.randrange(1, N+1)
W = random.randrange(1, N+1)
print(H, W)
for i in range(H):
    for j in range(W):
        if i == 0 and j == 0:
            print('.', end='')
        else:
            print('#' if random.random() < p else '.', end='')
    print()
