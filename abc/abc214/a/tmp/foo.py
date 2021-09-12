#!/usr/bin/env python3

from random import randrange

n = 10000
m = 10000
vmax = 10**9

a = [(randrange(vmax), 1) for i in range(n)]

# print('a=', a)
for i in range(m):
    newX = randrange(vmax);
    l = randrange(n)
    r = randrange(n)
    if l > r:
        (l, r) = (r, l)
    # print('(newX,l,r)=', newX, l, r)
    r += 1
    newA = []
    idx = 0
    state = 1
    for (x, k) in a:
        if l == idx:
            newA.append((newX, r - l))
        if idx + k <= l or r <= idx:
            idx += k
            newA.append((x, k))
            continue
        if l <= idx and idx + k <= r:
            idx += k
            continue
        if idx < l:
            newA.append((x, l - idx))
            newA.append((newX, r - l))
        if r < idx + k:
            newA.append((x, idx + k - r))
        idx += k
    a = newA
    # print('a=', a)
    print(len(a))
