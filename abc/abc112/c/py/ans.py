#!/usr/bin/env python3
import sys

def solve(n, ls_xyh):
    x0 = None
    for i in range(n):
        if ls_xyh[i][2] > 0:
            [x0,y0,h0] = ls_xyh[i]
            break
    cands = [(cx, cy, h0 + abs(cx - x0) + abs(cy - y0))
             for cx in range(101) for cy in range(101)]
    for [x,y,h] in ls_xyh:
        cands = [(cx, cy, ch) for (cx, cy, ch) in cands
                    if max(ch - abs(cx - x) - abs(cy - y), 0) == h]
    (xx, yy, hh) = cands[0]
    return ' '.join([str(xx), str(yy), str(hh)])

def readQuestion():
    ws = sys.stdin.readline().strip().split()
    n = int(ws[0])
    ls_xyh = [list(map(int, sys.stdin.readline().strip().split()))
              for j in range(n)]
    return (n, ls_xyh)

def main():
    print(solve(*readQuestion()))

# Uncomment before submission
main()

