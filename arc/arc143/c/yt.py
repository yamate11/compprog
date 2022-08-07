#!/usr/bin/env python3

#
#  Game Search
#
#  Positions should be represented by hashable objects, such as tuples.
#  Note that lists cannot be hashed.  To handle data, lists are more suitable than tuples,
#  so you may want to use expressions such as:
#         tuple([2, 5, 3])
#         list((3, 0, 2])
#         (0,) * 10
#  
#  The user should supply the following:
#    - parameters
#         such as N = 4 etc.
#    - function move(pos)
#         Returns the list of positions that can be moved from pos
#    - function main()
#         Usually, you should make a list of positions that you are interested in who wins
#         then all_judge(the_list_of_positions) returns the list of positions where
#         the player LOSES.
#

import sys

def debug(*msg):
    print(*msg, file=sys.stderr)


# The following are for ARC 105D

# SHOULD BE SUPPLIED BY THE USER.
# Parameters 
N = 3

# SHOULD BE SUPPLIED BY THE USER.
# Returns the list of legal moves from pos
def move(pos):
    res = []
    (tbags, tplates) = pos
    bags = list(tbags)
    plates = list(tplates)
    if sum(bags) > 0:
        for i in range(N):
            x = bags[i]
            if x == 0:
                continue
            for j in range(N):
                bags[i] = 0
                plates[j] += x
                res.append((tuple(bags), tuple(plates)))
                bags[i] = x
                plates[j] -= x
    else:
        for i in range(N):
            y = plates[i]
            if y > 0:
                for j in range(y):
                    plates[i] = j
                    res.append((tbags, tuple(plates)))
            plates[i] = y
    return res
    
# SHOULD BE SUPLIED BY THE USER.
def main():
    poss = []
    plates = (0,) * N
    A = 10
    bags = [0] * 10
    for i0 in range(A):
        bags[0] = i0
        for i1 in range(i0, A):
            bags[1] = i1
            for i2 in range(i1, A):
                bags[2] = i2
                poss.append((tuple(bags[:N]), plates))
    for p in all_judge(poss):
        print(p)

# wl[pos] == True  if the player at pos wins
# wl[pos] == False if the player at pos loses
wl = {}

# Need not be edited.
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

# Need not be edited.
# Argument poss is a list of positions
# Returns the sublist of poss, positions where a player there LOSES.
def all_judge(poss):
    return [p for p in poss if not judge(p)]

main()
