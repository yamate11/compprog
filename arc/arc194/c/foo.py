#!/usr/bin/env python3

v11= [72, 67, 46]
v10= [1, 22, 27, 52, 73, 79, 90, 97]
v01= [2, 13, 15, 54]

v10 = sorted(v10, reverse=True)

x = sum(v10) + sum(v11)

a = 0
for y in v10:
    x -= y
    a += x
    print(y, a)
for y in v01:
    x += y
    a += x
    print(y, a)
print(a)

