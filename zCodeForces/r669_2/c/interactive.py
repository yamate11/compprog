#!/usr/bin/env python3

#
# Simulator for interactive questions.
#

import sys
from random import randrange, shuffle
from subprocess import Popen, PIPE

#
#  Basically, you need to edit two functions
#    - session(sin, sprint)
#    - main()
#  Question (the hidden information that the program ./cans should reveal)
#  is set to dictionary (or list or whatever) quest

# In main(), you must do:
#   - Create a question and set it to variable quest
#   - call one_run(quest)
#
def main():
    global quest

    # quest = (5, [4, 3, 2, 5, 1])
    # one_run(quest)
    # exit(1)
    for _ in range(1000):
        n = randrange(1, 60)
        lst = list(range(1, n+1))
        shuffle(lst)
        quest = (n, lst)
        one_run(quest)
    warn('OK')
            
# session() is called from one_run().
#   This is the body of the simulator.  In this function, you can use
#     - function sprint()
#         to send something into the program ./cans
#     - stream sin
#         use it in a for loop to get input from ./cans
#   If the answer from ./cans is correct, just return from session().
#   Otherwise, call die() with some message.
def session(quest, sin, sprint):
    (n, lst) = quest
    sprint(n)
    cnt = 0
    for line in sin:
        sline = line.strip()
        if sline[0] == '!':
            ans = list(map(int, sline[2:].split()))
            if lst == ans:
                return 
            else:
                die(f'NG\nexp = {lst}\nact = {ans}')
        elif sline[0] == '?':
            if cnt >= 2 * n:
                die(f'query number exceeds.\nexp = {lst}')
            cnt += 1
            (dummy, xx, yy) = sline.split()
            x = int(xx)
            y = int(yy)
            if x <= 0 or n < x:
                die(f'x = {x}, out of range')
            if y <= 0 or n < y:
                die(f'y = {y}, out of range')
            sprint(lst[x-1] % lst[y-1])
        else:
            die("Unknown first char")

# You do not need to edit the following
def die(*arg):
    print(*arg, file=sys.stderr, flush=True)
    sys.exit(1)

def warn(*arg):
    print(*arg, file=sys.stderr, flush=True)

def one_run(quest):
    with Popen(['./cans'], encoding='UTF-8',
               stdin=PIPE, stdout=PIPE) as proc:
        def pout(*arg):
            print(*arg, file=proc.stdin, flush=True)
        session(quest, proc.stdout, pout)

main()

