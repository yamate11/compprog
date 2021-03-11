#!/usr/bin/env python3

import itertools, sys

N = None

def sat(ls):
    for i in range(N-1):
        if ls[i] < ls[i+1]: continue
        if ls[i] != N: return False
        else: break
    for i in range(N-1, 0, -1):
        if ls[i-1] > ls[i]: continue
        if ls[i] != N: return False
        else: break
    return True

def dist(ls1, ls2):
    dic = {}
    for i in range(N):
        dic[ls1[i]] = i
    lsX = [dic[ls2[i]] for i in range(N)]
    cnt = 0
    for i in range(N):
        for j in range(i+1, N):
            if lsX[i] > lsX[j]: cnt += 1
    return cnt

def main():
    global N

    # N = 5
    # assert(sat([1,2,3,4,5]))
    # assert(sat([5,4,3,2,1]))
    # assert(sat([1,3,5,4,2]))
    # assert(not sat([1,5,4,2,3]))
    # assert(not sat([5,4,2,3,1]))
    # assert(not sat([1,3,2,5,4]))

    # assert(dist([1,2,3,4,5], [1,2,3,5,4]) == 1)
    # assert(dist([1,2,3,4,5], [5,4,3,2,1]) == 10)
    # assert(dist([2,1,4,3,5], [1,2,3,4,5]) == 2)
    # assert(dist([2,1,4,3,5], [1,4,3,5,2]) == 4)
    # sys.exit(0)

    N = int(input())
    lstB = [int(s) for s in input().strip().split()]

    ans = 1e10
    for ls in itertools.permutations(range(1,N+1)):
        if not sat(ls): continue
        ans = min(ans, dist(lstB, ls))
    print(ans)

main()
