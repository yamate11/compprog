#!/usr/bin/env python3.6

import random

n = 2000
m = 2000
print(n, m)
for i in range(n):
    for j in range(m):
        if random.random() < 0.1:
            print('#', end='')
        else:
            print('.', end='')
    print()
