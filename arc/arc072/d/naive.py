#!/usr/bin/env python

N = 10
tbl = [[None for _ in range(N*2+1)] for x in range(N*2+1)]

def chk(x, y):
    if tbl[x][y] is not None: return tbl[x][y]
    for i in range(1, (x+2) // 2):
        if chk(x - 2*i, y+i):
            tbl[x][y] = False
            return False
    for i in range(1, (y+2) // 2):
        if chk(x + i, y - 2*i): 
            tbl[x][y] = False
            return False
    tbl[x][y] = True
    return True;

def main():
    for x in range(N):
        for y in range(N):
            print(x, y, chk(x, y))
main()
