#!/usr/bin/env python3

def main():
    L = int(input())
    t = 1
    s = 1
    for x in range(11):
        t *= (L - 1 - x)
        s *= (11 - x)
    print(t // s)

main()
