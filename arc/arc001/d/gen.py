#!/usr/bin/env python3

from random import randrange

N = 10
e = [0] * (N+1)
b = [0] * (N+1)
for i in range(N+1):
    b[i] = randrange(10)
    e[i] = b[i] + randrange(1,10)
s = b[0] + randrange(e[0] - b[0])
g = b[N] + randrange(e[N] - b[N])
print(N)
print(s, g)
for i in range(N+1):
    print(b[i], e[i])
    
