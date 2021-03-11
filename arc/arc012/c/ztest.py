#!/usr/bin/env python3


import random, subprocess
from random import randrange

brd = '.' x (19*19)
hist = [brd]
p = 0.3

def main():
    bcur = (9,9)
    bdir = (1,0)
    wcur = (9,8)
    wdir = (0,1)
    i = 0
    while True:
        (bcur, bdir) = getcd(bcur, bdir)
        e = dec(bcur)
        newBrd = brd[:e] + 'o' + brd[e+1:]
        hist.append(newBrd)
        ask(newBrd)
        (wcur, wdir) = getcd(wcur, wdir)
        e = dec(wcur)
        newBrd = brd[:e] + 'x' + brd[e+1:]
        hist.append(newBrd)
        judge = ask(newBrd)
    

main()


