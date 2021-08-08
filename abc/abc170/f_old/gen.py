#!/usr/bin/env python3

import argparse
from random import randrange

endmark = '^__=end=__^'

def val():
    if randrange(100) <= 20:
        return '@'
    return '.'

def genOne():

    H = 2
    W = 10
    K = 4
    brd = [[val() for w in range(W)] for h in range(H)]
    while True:
        r1 = randrange(H)
        r2 = randrange(H)
        c1 = randrange(W)
        c2 = randrange(W)
        if (r1, c1) == (r2, c2):
            continue
        if brd[r1][c1] == '@':
            continue
        if brd[r2][c2] == '@':
            continue
        break
    print(H, W, K)
    print(r1+1, c1+1, r2+1, c2+1)
    for r in range(H):
        print(''.join(brd[r]))

    
def main():
    ap = argparse.ArgumentParser();
    ap.add_argument('-r', '--repeat', action='store_true',
                    help='Repeatedly generates cases',)
    args = ap.parse_args()

    if args.repeat:
        while True:
            genOne()
            print(endmark)
    else:
        genOne()
    

main()
