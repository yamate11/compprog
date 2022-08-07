#!/usr/bin/env python3

import sys

def debug(*msg):
    print(*msg, file=sys.stderr)

# ARC 143C

N = 4
X = 2
Y = 1

# wl[pos] == True  if the player at pos wins
# wl[pos] == False if the player at pos loses
wl = {}

# SHOULD BE SUPPLIED BY THE USER.
# Returns the list of legal moves from pos
def move(pos):
    res = []
    (player, sts) = pos
    z = X if player == 0 else Y
    for x in range(1, 1 << N):
        if all([not (x >> i & 1) or sts[i] >= z for i in range(N)]):
            nsts = tuple([sts[i] - z if (x >> i & 1) else sts[i] for i in range(N)])
            res.append((1 - player, nsts))
    return res
    
# SHOULD NOT BE EDITED
# Returns True if a player at pos wins the game.
def judge(pos):
    if pos in wl:
        return wl[pos]
    for q in move(pos):
        if not judge(q):
            wl[pos] = True
            return True
    wl[pos] = False
    return False

# SHOULD NOT BE EDITED
# Argument poss is a list of positions
# Returns the sublist of poss, positions where a player there LOSES.
def all_judge(poss):
    return [p for p in poss if not judge(p)]

def main():
    A = 10
    poss = [(0, (i0, i1, i2, i3)) for i0 in range(A) for i1 in range(i0 + 1) for i2 in range(i1 + 1) for i3 in range(i2 + 1)]
    for p in all_judge(poss):
        print(p)

main()
