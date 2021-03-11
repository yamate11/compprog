#!/usr/bin/env python3


e = [0] * 15
e[10] = 0
e[9] = 1
for i in range(8, -1, -1):
    s = 0
    for j in range(1, 6):
        s += e[i + j]
    e[i] = 1 + s / 5
print(e)

    
