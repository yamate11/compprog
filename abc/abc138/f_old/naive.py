#!/usr/bin/env python3

def main():
    L, R = map(int, input().strip().split())
    cnt = 0
    for x in range(L, R+1):
        for y in range(x, R+1):
            if y % x == y ^ x:
                cnt += 1
    print(cnt)

main()
