#!/usr/bin/env python3

def main():
    def dist(p, q, r):
        if q == r:
            return 0
        for [t, col, dd] in nbr[q]:
            if t == p:
                continue
            z = dist(q, t, r)
            if z >= 0:
                if col == x:
                    return z + y
                else:
                    return z + dd
        return -1


    N, Q = map(int, input().split())
    nbr = [[] for a in range(N+1)]
    for i in range(N-1):
        a, b, c, d = map(int, input().split())
        nbr[a].append([b, c, d])
        nbr[b].append([a, c, d])
    for i in range(Q):
        x, y, u, v = map(int, input().split())
        print(dist(u, u, v))

    

main()
