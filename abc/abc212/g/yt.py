#!/usr/bin/env python3

p = 19

for x in range(1, p):
    q = x
    lst = [x]
    while q != 1:
        q = (q * x) % p
        lst.append(q)
    print(lst)
