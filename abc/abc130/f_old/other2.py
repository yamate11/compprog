#!/usr/bin/env python3

import sys
sys.setrecursionlimit(10**7)
INF = 10 ** 9
MOD = 10 ** 9 + 7
def YesNo(x): return 'Yes' if x else 'No'
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()

def main():
    N = II()
    xp9, xm9, xf9, yp9, ym9, yf9 = [-INF] * 6
    xp0, xm0, xf0, yp0, ym0, yf0 = [INF] * 6
    for _ in range(N):
        x, y, d = LS()
        x = int(x)
        y = int(y)
        if d == 'R':
            xp9 = max(xp9, x)
            xp0 = min(xp0, x)
            yf9 = max(yf9, y)
            yf0 = min(yf0, y)
        elif d == 'L':
            xm9 = max(xm9, x)
            xm0 = min(xm0, x)
            yf9 = max(yf9, y)
            yf0 = min(yf0, y)
        elif d == 'U':
            xf9 = max(xf9, x)
            xf0 = min(xf0, x)
            yp9 = max(yp9, y)
            yp0 = min(yp0, y)
        elif d == 'D':
            xf9 = max(xf9, x)
            xf0 = min(xf0, x)
            ym9 = max(ym9, y)
            ym0 = min(ym0, y)
    ts = [0]
    ts += [xf0 - xp0, xf9 - xp0, xf0 - xp9, xf9 - xp9]
    ts += [(xm0 - xp0) * 0.5, (xm9 - xp0) * 0.5, (xm0 - xp9) * 0.5, (xm9 - xp9) * 0.5]
    ts += [xm0 - xf0, xm9 - xf0, xm0 - xf9, xm9 - xf9]
    ts += [yf0 - yp0, yf9 - yp0, yf0 - yp9, yf9 - yp9]
    ts += [(ym0 - yp0) * 0.5, (ym9 - yp0) * 0.5, (ym0 - yp9) * 0.5, (ym9 - yp9) * 0.5]
    ts += [ym0 - yf0, ym9 - yf0, ym0 - yf9, ym9 - yf9]
    ts = [t for t in ts if t >= 0]
    ans = 10 ** 18
    for t in ts:
        xmax = max(xf9, xm9 - t, xp9 + t)
        xmin = min(xf0, xm0 - t, xp0 + t)
        ymax = max(yf9, ym9 - t, yp9 + t)
        ymin = min(yf0, ym0 - t, yp0 + t)
        tmp = (xmax - xmin) * (ymax - ymin)
        ans = min(ans, tmp)

    return ans

print(main())
