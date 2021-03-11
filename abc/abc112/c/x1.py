#!/usr/bin/env python3

n = 101*101-1
print(n)
for i in range(101):
    for j in range(101):
        if (i,j) != (50,50):
            print(i, j, 0)
