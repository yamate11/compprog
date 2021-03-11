#!/usr/bin/env python3

from random import randrange

N = 100000
lst = []
for i in range(N):
    lst.append(str(randrange(-30, 31)))
print(N)
print(' '.join(lst))
