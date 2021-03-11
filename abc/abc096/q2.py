#!/usr/bin/env python3

def solve(a, b, c, k):
    val = a
    for x in [b, c]:
        if val < x:
            val = x
    remain = a + b + c - val
    for i in range(k):
        val *= 2
    return val + remain

def readQuestion():
    import sys
    line = sys.stdin.readline()
    sline = line.rstrip()
    str_a, str_b, str_c = sline.split(' ')
    a = int(str_a)
    b = int(str_b)
    c = int(str_c)
    line = sys.stdin.readline()
    str_k = line.rstrip()
    k = int(str_k)
    return a, b, c, k

def main():
    a, b, c, k = readQuestion()
    ans = solve(a, b, c, k)
    print(ans)

if __name__ == '__main__':
    main()
