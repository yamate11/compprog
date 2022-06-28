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
dp = [0] * (N+1)
res = [[0] * 9 for _ in [0] * (N+1)]
C = liinput()

for i in range(8, -1, -1):
    w = C[i]
    for j in range(w, N+1):
        if dp[j-w] + 1 > dp[j]:
            dp[j] = dp[j-w] + 1
            for k in range(9):
                res[j][k] = res[j-w][k]
            res[j][i] += 1
ans = []

for i in range(8, -1, -1):
    ans.append(str(i+1)*res[-1][i])
print(''.join(ans))
