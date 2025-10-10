#!/usr/bin/env python3

P = 998244353

def solve():
    A, B, C = map(int, input().split(' '))
    lim = 135
    j0 = 0
    k0 = 1
    powA = 1
    j = 0
    for k in range(1, lim + 1):
        powA *= A
        while True:
            if powA % C != 0:
                break
            powA //= C
            j += 1
        if j * k0 > k * j0:
            j0 = j
            k0 = k
    ans = (j0 * B) // k0
    print(ans % P)

def main():
    t = int(input())
    for _ in range(t):
        solve()

main()
