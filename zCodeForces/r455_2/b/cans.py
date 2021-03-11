#!/usr/bin/env python3


n = int(input())
r = (n + 1) // 2
x = 1
y = 1
for i in range(r):
    x *= n - i
    y *= r - i
print(x // y)
