#!/usr/bin/env python3

import random

n=1000
c=100

lst = [1]
x = 1
for i in range(2,n+1):
    y = random.randrange(1,2000)
    x += y
    lst.append(x)
print(n, c)
print(" ".join(map(str, lst)))
