#!/usr/bin/env python3

def comp(t, i, v, cP, cM):
    if D[i] == cP:
        return v[i] + t;
    if D[i] == cM:
        return v[i] - t;
    return v[i];

def main():
    global N, X, Y, D
    N = int(input())
    X = []
    Y = []
    D = []
    for i in range(N):
        (sx,sy,sd) = input().split()
        X.append(int(sx));
        Y.append(int(sy));
        D.append(sd);
    tt = 0
    answer = 1e18;
    prevXMax = 1e18;
    prevYMax = 1e18;
    prevXMin = -1e18;
    prevYMin = -1e18;
    while True:
        t = tt / 2;
        xs = [comp(t, i, X, 'R', 'L') for i in range(N)]
        ys = [comp(t, i, Y, 'U', 'D') for i in range(N)]
        xMax = max(xs)
        xMin = min(xs)
        yMax = max(ys)
        yMin = min(ys)
        v = (xMax - xMin) * (yMax - yMin)
        answer = min(answer, v)
        # print(xMax, xMin, yMax, yMin, prevXMax, prevXMin, prevYMax, prevYMin, prevXMax - prevXMin, xMax - xMin, prevYMax - prevYMin, yMax - yMin)
        if (prevXMax - prevXMin <= xMax - xMin and
            prevYMax - prevYMin <= yMax - yMin):
            break
        (prevXMax, prevYMax, prevXMin, prevYMin) = \
            (xMax, yMax, xMin, yMin)
        tt += 1;
    print(answer)

main()
