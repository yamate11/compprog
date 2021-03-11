#!/usr/bin/python3

import sys

class MyException(Exception):
    pass

def byC(arr, i, j):
    tmp_dict = {}
    for p in arr:
        if p[i] not in tmp_dict:
            tmp_dict[p[i]] = []
        tmp_dict[p[i]].append(p[j])
    u = []
    v = []
    for x in sorted(tmp_dict.keys()):
        u.append(x)
        v.append(sorted(tmp_dict[x]))
    return (u, v)

f = sys.stdin
n, k = map(int, next(f).rstrip().split(' '))
points = []
for line in f:
    (x, y) = map(int, line.rstrip().split(' '))
    points.append((x, y))
ptsX, byXraw = byC(points, 0, 1)
ptsY, byYraw = byC(points, 1, 0)

xN = len(ptsX)
yN = len(ptsY)

revX = {}
for i in range(xN):
    revX[ptsX[i]] = i
revY = {}
for i in range(yN):
    revY[ptsY[i]] = i

byX = map(map (lambda y: revY[y]), byXraw)
byY = map(map (lambda x: revX[x]), byYraw)

minArea = (ptsX[xN - 1] - ptsX[0]) * (ptsY[yN - 1] - ptsY[0])

for y0 in range(yN):
    w = [0 for x in range(xN)]
    for x in byY[y0]:
        w[x] = 1
    for y1 in range (y0 + 1, yN):
        try:
            for x in byY[y1]:
                w[x] += 1
            x0 = 0
            while x0 < xN:
                x1 = x0 + 1
                c = w[x0] + w[x1]
                while c < k:
                    if x1 == xN:
                        raise MyException
                    c += w[x1]
                    x1 += 1
                while c - w[x0] >= k and x0 + 1 < x1:
                    c -= w[x0]
                    x0 += 1
                minArea = min([minArea,
                               (ptsY[y1] - ptsY[y0]) * (ptsX[x1] - ptsX[x0])])
        except MyException:
            pass

print(minArea)
