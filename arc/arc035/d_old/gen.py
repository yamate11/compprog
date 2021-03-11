#!/usr/bin/env python3

from random import randrange

N = 2*10**5
Q = 2*10**5
step = 9
print(N)
p = 1
q = 1
vec = []
for i in range(N):
    p += randrange(1,step)
    q += randrange(1,step)
    vec.append((p,q))
    print(p, q)
print(Q)
for i in range(Q):
    t = randrange(1,3)
    if t == 1:
        k = randrange(N)
        if k == 0:
            p0 = 1
            q0 = 1
        else:
            p0 = vec[k][0]
            q0 = vec[k][1]
        if k == N-1:
            p1 = vec[k][0] + step
            q1 = vec[k][1] + step
        else:
            p1 = vec[k+1][0]
            q1 = vec[k+1][1]
        p = randrange(p0, p1+1)
        q = randrange(q0, q1+1)
        vec[k] = (p,q)
    else:
        l1 = randrange(1, N)
        r1 = randrange(l1+1, N+1)
        l2 = randrange(1, N)
        r2 = randrange(l2+1, N+1)
        print(2, l1, r1, l2, r2)
