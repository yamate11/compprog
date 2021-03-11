#!/usr/bin/env python3

vec = [0] * 100
vec[0] = 1
vec[1] = 1
for i in range(20):
    vec[i+2] = vec[i+1] + vec[i]
    print(i+2, vec[i+2])
