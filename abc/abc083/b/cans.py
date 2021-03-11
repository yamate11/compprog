#!/usr/bin/env python3

def dsum(n):
    ret = 0
    while n > 0:
        ret += n % 10
        n //= 10
    return ret

def main():
    (N, A, B) = map(int, input().strip().split())
    ans = 0
    for i in range(1, N+1):
        x = dsum(i)
        if A <= x and x <= B:
            ans += i
    print(ans)

main()
