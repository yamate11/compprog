#!/usr/bin/env python3

import sys

def solve(s):
    count = 0
    for c in s:
        if c == 'o':
            count += 1
    return 700 + count * 100

def main():
    line = list(sys.stdin)[0].rstrip()
    print(solve(line))

if __name__ == '__main__':
    main()
