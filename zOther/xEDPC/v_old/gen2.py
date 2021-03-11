#!/usr/bin/env python3

n = 10**5
m = 16*9*5*7*11*13*17*19
print(n,m)

for i in range(1,n):
    print(1 + i//20000, 1 + i)
    
