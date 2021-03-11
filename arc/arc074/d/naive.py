#!/usr/bin/env python3

def calc(N, lst):
    return sum(lst[0:N]) - sum(lst[N:2*N])

def sch(N, A, len, take, remLst):
    if take == 0:
        return calc(N, A[:len] + remLst)
    if take == len:
        return calc(N, remLst)
    x1 = sch(N, A, len-1, take-1, remLst)
    x2 = sch(N, A, len-1, take, [A[len-1]] + remLst)
    return max(x1, x2)

def main():
    N = int(input())
    A = list(map(int, input().split()))
    x = sch(N, A, 3*N, N, [])
    print(x)

main()
