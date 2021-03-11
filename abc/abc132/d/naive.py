#!/usr/bin/env python3

def fact(n):
    if n == 0:
        return 1
    return n * fact(n-1)

def combi(n, r):
    return fact(n) // (fact(r) * fact(n-r))

def listCombi(n, k):
    if n == 0:
        if k == 0:
            return ['']
        else:
            return []
    if k == 0:
        return [' ' * n]
    return ['B' + s for s in listCombi(n-1, k-1)] \
        +  [' ' + s for s in listCombi(n-1, k)]


def main():
    (N,K) = map(int,input().strip().split())
    cnt = [0 for _ in range(K+1)]
    for s in listCombi(N, K):
        idx = len(s.strip().split())
        cnt[idx] += 1
    for i in range(1,K+1):
        print(cnt[i])

main()
