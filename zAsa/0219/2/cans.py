#!/usr/bin/env python3

L = int(input())

p = 1
q = 1
for i in range(11):
    p *= L - 1 - i
    q *= 11 - i
print(p // q)
