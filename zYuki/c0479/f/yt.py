#!/usr/bin/env python3

t0 = 123 * 11

vec = [False for i in range(2 * t0)]

for i in range(23):
    for j in range(23):
        for k in range(23):
            s = i + j + k
            t = i * 111 + j * 11 + k
            if t < t0 and not vec[t] and 2*i < s and 2*j < s and 2*k < s:
                vec[t] = True

for i in range(t0):
    print(i, vec[i])
    
