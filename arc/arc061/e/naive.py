#!/usr/bin/env python3

def main():
    N,M = map(int, input().strip().split())
    P = [0] * M;
    Q = [0] * M;
    C = [0] * M;
    nbr = [[] for _ in range(N+1)]
    for i in range(M):
        P[i], Q[i], C[i] = map(int, input().strip().split())
        nbr[P[i]].append((Q[i], C[i]))
        nbr[Q[i]].append((P[i], C[i]))
    cLim = max([C[i] for i in range(M)]) + 1 if M > 0 else 1
    st = [(s,c) for s in range(1, N+1) for c in range(1, cLim)]
    dist = {(s,c): (N+10) for s in range(1, N+1) for c in range(1, cLim)}
    for c in range(1, cLim):
        dist[(1,c)] = 1
    while True:
        changed = False
        for s in range(1, N+1):
            for c in range(1, cLim):
                for (q1, c1) in nbr[s]:
                    addD = 0 if c == c1 else 1
                    newDist = dist[(s,c)] + addD
                    if newDist < dist[(q1, c1)]:
                        changed = True
                        dist[(q1, c1)] = newDist
        if not changed: break
    dd = min([dist[(N,c)] for c in range(1, cLim)]) if cLim > 1 else N+10
    if dd == N+10: dd = -1
    print(dd)

main()
