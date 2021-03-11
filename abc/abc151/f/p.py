#!/usr/bin/env python3

import math, sys

pts = [(10, 9),
 (5, 9),
 (2, 0),
 (0, 0),
 (2, 7),
 (3, 3),
 (2, 5),
 (10, 0),
 (3, 7),
 (1, 9)];

def dist(u, v):
    (ux, uy) = u
    (vx, vy) = v
    dx = ux - vx;
    dy = uy - vy;
    return math.sqrt(dx*dx + dy*dy)

def maxDist(p):
    # print(f"maxDist({p})")
    vmax = 0
    for pt in pts:
        d = dist(pt,p)
        vmax = max(vmax, d)
        # print(f"    pt = {pt}, d = {d}, vmax = {vmax}")
    return vmax

def getNextCand(cand, size):
    (xc, yc) = cand
    
    rMin = 10000;
    for i in range(-2, 3):
        for j in range(-2, 3):
            y = yc + i * size / 2;
            x = xc + j * size / 2;
            r = maxDist((x,y))
            if r < rMin:
                (rMin, xMin, yMin) = (r, x, y)
            print(f"({x:.2f},{y:.2f}) {r:.8f}", end=';  ')
        print()
    return (xMin, yMin)

def main():
    (xA, yA) = (5.0, 4.5)
    (cx, cy) = (500, 500)
    size = 1000
    while True:
        (cxN, cyN) = getNextCand((cx,cy), size)
        print(cxN, cyN, size);
        if abs(cxN - xA) > 1e-9 + size /2 or abs(cyN - yA) > 1e-9 + size/2:
            print('abort')
            sys.exit(1)
        (cx, cy) = (cxN, cyN)
        size /= 2

main()
