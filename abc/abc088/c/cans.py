#!/usr/bin/env python3

c = []
def solve():
    for i in range(3):
        c.append(list(map(int, input().split())))
    d0 = c[0][1] - c[0][0]
    d1 = c[0][2] - c[0][1]
    for i in range(3):
        if c[i][1] - c[i][0] != d0:
            return False
        if c[i][2] - c[i][1] != d1:
            return False
    e0 = c[1][0] - c[0][0]
    e1 = c[2][0] - c[1][0]
    for i in range(3):
        if c[1][i] - c[0][i] != e0:
            return False
        if c[2][i] - c[1][i] != e1:
            return False
    return True

def main():
    print("Yes" if solve() else "No")

main()
