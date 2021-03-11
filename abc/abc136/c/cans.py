#!/usr/bin/env python3

N = int(input())
lst = [int(h) for h in input().split()]

def judge():
    cur = lst[0]
    for i in range(1, N):
        if lst[i] < cur - 1:
            return False
        if lst[i] > cur:
            cur = lst[i]
    return True

if judge():
    print('Yes')
else:
    print('No')
    
