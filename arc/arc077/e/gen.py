#!/usr/bin/env python3

import random

n = 10**5
m = 10**5
b = -1
lst = []
for i in range(n):
    while True:
        a = random.randrange(1,m+1)
        if a != b:
            break
    b = a
    lst.append(a)
print(n,m)
print(' '.join(map(str,lst)))
