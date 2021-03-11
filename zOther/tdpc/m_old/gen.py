#!/usr/bin/env python3

import random

h = 10**9
r = 16
x = [[0 for j in range(r)] for i in range(r)]
for i in range(r):
    for j in range(i+1,r):
        if random.random() >= 0.5:
            x[i][j] = 1
            x[j][i] = 1
print(h,r)
for b in x:
    print(' '.join(map(str,b)))
    
