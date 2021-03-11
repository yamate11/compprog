#!/usr/bin/env python3

import random

n = 5
m = 3

print(n, m)
for i in range(m):
    k = random.randrange(1, n+1)
    lst = random.sample(range(1,n+1), k)
    print(k, ' '.join(map(str,lst)))
ps = [random.randrange(2) for _ in range(m)]
print(' '.join(map(str, ps)))
