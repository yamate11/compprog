#!/usr/bin/env python3

from random import randrange

N = 6;
print(N)
hd = [randrange(10) for _ in range(N)]
cur = 0
H = []
for i in range(N):
    cur += hd[i]
    H.append(cur)
M = [0] * N
S = [0] * N
E = [0] * N
T = N*3
for i in range(N):
    M[i] = randrange(1, N+1)
    while True:
        s = randrange(T)
        e = randrange(T)
        if s == e:
            continue
        if e < s:
            (e, s) = (s, e)
        break
    S[i] = s
    E[i] = e
print(" ".join([str(x) for x in H]))
for i in range(N):
    print(M[i], S[i], E[i])
            
