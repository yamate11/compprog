#!/usr/bin/env python3


def main():
    N = int(input())
    A = list(map(int, input().strip().split()))
    cnt = 0
    for x in A:
        while x % 2 == 0:
            cnt += 1
            x //= 2
    print(cnt)


main()
