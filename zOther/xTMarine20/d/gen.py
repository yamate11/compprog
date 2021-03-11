#!/usr/bin/env python3

import argparse
from random import randrange

endmark = '^__=end=__^'

def genOne():

    # N = int(2e5)
    # N = randrange(100)
    N = randrange(1, 40)
    print(N)
    for i in range(N):
        print(randrange(1, 10), randrange(1, 10))
        # print(randrange(1, 1e5+1), randrange(1, 1e5+1))
    # Q = N
    Q = 8
    print(Q)
    for q in range(1, Q+1):
        print(randrange(1, N+1), randrange(40))
        # print(q, randrange(1e5+1))
    
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
