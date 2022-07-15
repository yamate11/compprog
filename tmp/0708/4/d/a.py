#!/usr/bin/env python3

from random import choice

def main():
    n = 30000
    s = ""
    for i in range(n):
        s += choice("0123456789")
    print(n)
    print(s)

main()
