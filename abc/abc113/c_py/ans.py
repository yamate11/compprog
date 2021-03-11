#!/usr/bin/env python3

import sys

def solve(n, m, ls_py):
    # Uncomment the following if you want to check the input.
    # print('n =', n)
    # print('m =', m)
    # print('ls_py =', ls_py)
    perP = [[] for i in range(n+1)]
    for (i,[p,y]) in enumerate(ls_py):
        perP[p].append((y,i))
    seqs = []
    for p in range(n+1):
        perP[p].sort()
        for (o, (_, i)) in enumerate(perP[p], start=1):
            seq = '{:06d}{:06d}'.format(p, o)
            seqs.append((i,seq))
    return '\n'.join([seq for (i,seq) in sorted(seqs)])


def readQuestion():
    ws = sys.stdin.readline().strip().split()
    n = int(ws[0])
    m = int(ws[1])
    ls_py = [list(map(int, sys.stdin.readline().strip().split())) for j in range(m)]
    return (n, m, ls_py)

def main():
    print(solve(*readQuestion()))

# Uncomment before submission
main()
