#!/usr/bin/env python3

N = 30

vec = [set() for i in range(N+1)]

vec[1] = set([0])
for i in range(3,N+1,2):
    for j in range(1, 1 + (i - 1) // 2, 2):
        k = i - 1 - j
        for x in vec[j]:
            for y in vec[k]:
                p = 1 if j * 2 <= k else 0
                vec[i].add(p + x + y)
for i in range(3, N+1, 2):
    print(i, vec[i])
    

                    
