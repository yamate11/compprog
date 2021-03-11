#!/usr/bin/env python3

import itertools

def main():
    (N,M) = map(int,input().split())
    A = []
    B = []
    C = []
    D = []
    for i in range(N):
        (a, b) = map(int, input().split())
        A.append(a)
        B.append(b)
    for i in range(M):
        (a, b) = map(int, input().split())
        C.append(a)
        D.append(b)

    def chk(lstM, lstF):
        cnt = 0
        for (i,x) in enumerate(lstM):
            y = lstF[i]
            if B[x] <= C[y] and A[x] >= D[y]: cnt += 1
        return cnt

    ans = 0
    if N <= M:
        for lst in itertools.permutations(range(M), N):
            ans = max(ans, chk(range(N), lst))
    else:
        for lst in itertools.permutations(range(N), M):
            ans = max(ans, chk(lst, range(M)))
    print(ans)

main()

