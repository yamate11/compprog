#!/usr/bin/env python3

def solve(a, b):
    if a <= b:
        return a
    else:
        return a - 1

def readQuestion():
    import sys
    line = sys.stdin.readline()
    sline = line.rstrip()
    str_a, str_b = sline.split(' ')
    a = int(str_a)
    b = int(str_b)
    return a, b

def main():
    a, b = readQuestion()
    ans = solve(a, b)
    print(ans)

if __name__ == '__main__':
    main()
