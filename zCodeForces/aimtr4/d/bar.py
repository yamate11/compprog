#!/usr/bin/env python3

for k in range(1, 200):
    n = k * 10
    print(n,  ( (50000 - n) / 50000 ) ** (2000 - n) )
    
