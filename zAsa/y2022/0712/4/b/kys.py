#!/usr/bin/env python3

import sys
input = sys.stdin.readline
def iinput(): return int(input())
def sinput(): return input().rstrip()
def i0input(): return int(input()) - 1
def linput(): return list(input().split())
def liinput(): return list(map(int, input().split()))
def miinput(): return map(int, input().split())
def li0input(): return list(map(lambda x: int(x) - 1, input().split()))
def mi0input(): return map(lambda x: int(x) - 1, input().split())
INF = 10**20
MOD = 1000000007

N = iinput()
A = liinput()
B = liinput()

ctr = 0

for a, b in zip(A, B):
    if a <= b:
        ctr += (b - a) // 2
    else:
        ctr -= a - b

if ctr >= 0:
    print('Yes')
else:
    print('No')
