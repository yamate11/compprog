#!/usr/bin/env python3

(N, Y) = map(int, input().split())

for c in range(N+1):
    if Y < c * 10000:
        break
        
    
