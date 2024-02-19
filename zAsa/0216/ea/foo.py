#!/usr/bin/env python3

p = [4, 9, 5, 7, 11, 13, 17, 19, 23]
a = 0
m = 1
for x in p:
    a += x
    m *= x
print(a, m)
