#!/usr/bin/env python3

from queue import PriorityQueue;
from math import hypot

def main():
    N = int(input())
    X = [None for _ in range(N)]
    Y = [None for _ in range(N)]
    T = [None for _ in range(N)]
    R = [None for _ in range(N)]
    for i in range(N):
        X[i], Y[i], T[i], R[i] = map(int, input().split())
    tt = [[hypot(X[i] - X[j], Y[i] - Y[j]) / min(T[i], R[j])
           for j in range(N)] for i in range(N)]
    atm = [1e10 for _ in range(N)]
    pque = PriorityQueue();
    atm[0] = 0
    pque.put((0.0, 0))
    while (not pque.empty()):
        (t, i) = pque.get()
        if t > atm[i]: continue
        for j in range(N):
            newT = atm[i] + tt[i][j]
            if newT < atm[j]:
                atm[j] = newT
                pque.put((newT, j))
    atm.sort()
    vmax = max([atm[i] + (N-1 - i) for i in range(N)])
    print(vmax)
        

main()
