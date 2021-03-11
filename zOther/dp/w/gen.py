#!/usr/bin/env python3

import random

n = 2*10**5
m = 2*10**5
print(n,m)
for i in range(m):
    l = random.randrange(1,n+1)
    r = random.randrange(l,n+1)
    a = random.randrange(-10**9,10**9+1)
    print(l,r,a)
