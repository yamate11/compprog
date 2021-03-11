#!/usr/bin/env python3

N = int(input())
lstA = [int(a) for a in input().split()]

def round():
    for i in range(len(lstA)):
        if lstA[i] % 2 == 0:
            lstA[i] //= 2
        else:
            return False
    return True

cnt = 0
while round():
    cnt += 1
print(cnt)
