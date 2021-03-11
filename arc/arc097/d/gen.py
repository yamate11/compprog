#!/usr/bin/env python3

import random

n = 10**5
m = 10**5

# n = 5
# m = 5

x = list(range(1,n+1))
random.shuffle(x)

print(n,m)
print(' '.join(map(str,x)))
for i in range(m):
    while True:
        x = random.randrange(1,n+1)
        y = random.randrange(1,n+1)
        if x != y:
            break
    print(x,y)
