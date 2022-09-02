#!/usr/bin/env python3

import sys

def main():
    N, K = map(int, input().split())
    def sch(vec, i):
        if i == N:
            print([y + 1 for y in vec])
            sys.exit(0)
        for j in range(N):
            if abs(i - j) < K:
                continue
            if j in vec:
                continue
            sch(vec + [j], i + 1)
    sch([], 0)
    print(-1)


main()
