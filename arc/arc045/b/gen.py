#!/usr/bin/env python3

import random

N = random.randrange(1, 3)
i = 0
w = [0 for _ in range(N+1)]
vec = []
while True:
    covered = True
    for j in range(1, N+1):
        if w[j] == 0:
            covered = False
            break
    if covered:
        break
    s = random.randrange(1, N+1)
    t = random.randrange(s, N+1)
    for j in range(s, t+1):
        w[j] += 1
    vec.append((s, t))
print(N, len(vec))
for (s, t) in vec:
    print(s, t)
    
