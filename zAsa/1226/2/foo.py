#!/usr/bin/env python3

def main():
    n, a, b, c, d = map(int, input().split())
    if b == 0 and c == 0:
        if a == 0 or d == 0:
            print("Yes\n")
        else:
            print("No\n")
    else:
        if abs(b - c) <= 1:
            print("Yes\n")
        else:
            print("No\n")

main()

