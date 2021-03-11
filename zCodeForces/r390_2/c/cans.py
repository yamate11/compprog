#!/usr/bin/env python3

import re, sys

def debug(*msg):
    print(*msg, file=sys.stderr)

def solve():
    def parse(line):
        mo = re.match(r'(.*?):(.*)', line)
        assert(mo)
        name, text = mo[1], mo[2]
        if name == '?':
            speaker = -1
        else:
            assert (name in revP)
            speaker = revP[name]
        appears = [False] * n
        for x in re.findall(r'\w+', text):
            if x in revP:
                appears[revP[x]] = True
        return (speaker, text, appears)

    def add_hist(j):
        for hist in prev:
            if hist and hist[len(hist) - 1] == j:
                continue
            cur.append(hist + [j])
            return

    n = int(input())
    P = input().strip().split()
    revP = {P[i] : i for i in range(n)}
    m = int(input())
    lines = []
    for i in range(m):
        lines.append(sys.stdin.readline().strip())
    cur = [[]]
    texts = []
    for i in range(m):
        prev = cur
        cur = []
        (speaker, text, appears) = parse(lines[i])
        texts.append(text)
        if speaker >= 0:
            add_hist(speaker)
        else:
            for j in range(n):
                if not appears[j]:
                    add_hist(j)
        if not cur:
            print("Impossible")
            return
    debug("cur=", cur, "texts=", texts, "revP=", revP)
    for i in range(m):
        print(f'{P[cur[0][i]]}:{texts[i]}')
        


def main():
    t = int(input())
    for tt in range(t):
        solve()

main()
