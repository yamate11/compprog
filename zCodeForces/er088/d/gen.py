#!/usr/bin/env python3

N = 80000
lst = []
for i in range(N):
    if i % 2 == 0:
        lst.append('1')
    else:
        lst.append('-1')
print(N)
print(' '.join(lst))
