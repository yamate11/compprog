#!/usr/bin/env python3

import sys, itertools

def solve(s, gx, gy):
    dic = {'W': [(0,  1), (2,  1), (4,  1)],
           'X': [(0, -1), (3,  1), (5,  1)],
           'Y': [(1,  1), (2, -1), (5, -1)],
           'Z': [(1, -1), (3, -1), (4, -1)],
          }
    if gx == 0 and gy == 0: return True
    gxP, gyP = abs(gx), abs(gy)
    cnt = [0] * 6
    ctpt = [1, 0, 3, 2, 5, 4]
    for c in s:
        for (i, a) in dic[c]:
            cnt[i] += a
            s, t = abs(cnt[i]), abs(cnt[ctpt[i]])
            if check(s, t, gx, gy) or check(s, t, gy, gx):
                return True
    return False

def check(s, t, gx, gy):
    return s == gx and t == gy

def readQ():
    [line1, line2] = [line for line in sys.stdin]
    s = line1.strip()
    [gx, gy] = map(int, line2.split())
    return (s, gx, gy)

def main():
    print('Yes' if solve(*readQ()) else 'No')

main()
