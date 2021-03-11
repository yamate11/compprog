#!/usr/bin/env python3

import argparse, sys
from random import randrange, choice

# Function generate() should yield test cases of type string repeatedly.
# E.g.,
#    def generate():
#        for x in range(1, 10):
#            for cdir in ['N', 'E', 'S', 'W']:
#                yield f'{x}\n{cdir}\n'
# or E.g.,
#    def generate():
#        while True:
#            x = randrange(1, 10)
#            cdir = choice(['N', 'E', 'S', 'W'])
#            case = f'''{x}
#    {cdir}
#    '''
#            yield case

def generate():
    for N in range(1, 9):
        for M in range(N, 9):
            yield f'{N} {M}\n'

######################################################################
# Hope that you need not edit the following code.

end_mark = '^__=end=__^'
end_file_mark = '^__=end_file=__^'

def main():
    ap = argparse.ArgumentParser();
    ap.add_argument('-r', '--repeat', action='store_true',
                    help='Repeatedly generates cases',)
    args = ap.parse_args()

    try:
        if args.repeat:
            for s in generate():
                print(s.rstrip())
                print(end_mark)
            print(end_file_mark)
        else:
            for (i, s) in enumerate(generate()):
                print(s.rstrip())
                print(end_mark)
                if (i == 4):
                    break
    except BrokenPipeError as e:
        # print('caught: BrokenPipeError', file=sys.stderr)
        pass

main()
