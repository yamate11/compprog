#!/usr/bin/env python3

from math import sqrt

def main():
    N = int(input())
    k = int(sqrt(2 * N)) + 1
    if N < 3 or k * (k - 1) // 2 != N:
        print("No")
        return
    print("Yes")
    print(k)
    ans = [[] for _ in range(k)]
    t = 1
    for i in range(k):
        for j in range(i + 1, k):
            ans[i].append(t)
            ans[j].append(t)
            t += 1
    for i in range(k):
        print(len(ans[i]), end=' ')
        print(' '.join(map(str, ans[i])))

main()
