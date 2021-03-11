#!/usr/bin/env python3

import random

n = 5*10**4
m = 10**5

print(n,m)
for _ in range(m):
    while True:
        a = random.randrange(1,n+1)
        b = random.randrange(1,n+1)
        if a != b:
            break
    print(a,b)
        
