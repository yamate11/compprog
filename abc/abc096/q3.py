#!/usr/bin/env python3

def readQuestion():
    import sys
    h, w = map(int, sys.stdin.readline().split(' '))
    p = [[] for i in range(h)]
    for (i, line) in enumerate(sys.stdin):
        p[i] = list(map(lambda x:line[x] == '#', range(w)))
    return h, w, p

def mkNbr(s):
    nb = [[i-1,i+1] for i in range(s)]
    nb[0] = [1] if s > 1 else []
    nb[s-1] = [s-2] if s > 1 else []
    return nb

def solve(h, w, p):
    def hasNbr(i, j):
        return any((p[y][j] for y in nbH[i])) or \
               any((p[i][x] for x in nbW[j]))

    nbH = mkNbr(h)
    nbW = mkNbr(w)
    return 'Yes' if all((not p[i][j] or hasNbr(i,j)
                         for i in range(h) for j in range(w))) \
                 else 'No'

def main():
    h, w, p = readQuestion()
    print(solve(h, w, p))

if __name__ == '__main__':
    main()
