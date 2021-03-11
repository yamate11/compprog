#!/usr/bin/env python

def powerset(n):
    if n == 0:
        return [[]]
    ret = []
    for y in powerset(n-1):
        ret.append(y)
        ret.append(y + [n-1])
    return ret

myInf = 10**9

def main():
    N, M = map(int,input().split())
    kss = [None for _ in range(M)]
    lstA = [0 for _ in range(M)]
    for i in range(M):
        a, b = map(int, input().split())
        cs = list(map(int, input().split()))
        lstA[i] = a
        kss[i] = cs

    def chk(xs):
        seen = [0 for _ in range(N+1)]
        ss = 0
        for x in xs:
            ss += lstA[x]
            for c in kss[x]:
                seen[c] = 1
        if sum(seen) != N:
            return myInf
        return ss

    val = myInf
    for xs in powerset(M):
        val = min(val, chk(xs))
    if val == myInf:
        print(-1)
    else:
        print(val)

main()
