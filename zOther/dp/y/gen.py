#!/usr/bin/env python3

import random

h = 10**5
w = 10**5
n = 3000
print(h,w,n)

ss = set()
ss.add ((1,1))
ss.add ((h,w))

for i in range(n):
    while True:
        r = random.randrange(1,h+1)
        c = random.randrange(1,w+1)
        if (r,c) not in ss:
            break
    ss.add((r,c))
    print(r,c)
    
