#!/usr/bin/python3

import sys

numBridge = 0
visited = set()

def singletonSet(x):
    r = set()
    r.add(x)
    return r

def dfs(start, stack):
#    print("dfs: stack = {}".format(stack))
    global numBridge
#    print("added {} to visited".format(start))
    visited.add(start)
    tree[start] = []
    for v in nbr[start]:
#        print("checking {}->{}".format(start, v))
        if v in done[start]:
            pass
        else:
            done[v].add(start)
            tree[start].append(v)
            if v in visited:
#                print("visited {}->{}".format(start, v))
                loop[start].add(v)
                while not v in stack:
                    w = revtree[v]
                    loop[w].add(v)
                    v = w
                t = v
#                print("common top is {}".format(t))
                v = start
                while v != t:
                    w = revtree[v]
                    loop[w].add(v)
                    v = w
            else:
                revtree[v] = start
                dfs(v, stack.union(singletonSet(start)))

def count():
    c = 0
    for p in range(1, n + 1):
#        print("tree[{}] = {}".format(p, tree[p]))
#        print("loop[{}] = {}".format(p, loop[p]))
        c += len(tree[p]) - len(loop[p])
    return c

f = sys.stdin
n, m = map(int, next(f).rstrip().split(' '))
nbr     = [[]    for _ in range(n + 1)]
tree    = [[]    for _ in range(n + 1)]
done    = [set() for _ in range(n + 1)]
revtree = [None  for _ in range(n + 1)]
loop    = [set() for _ in range(n + 1)]
for line in f:
    (p, q) = map(int, line.rstrip().split(' '))
#    print("p, q = {}, {}".format(p, q))
    nbr[p].append(q)
    nbr[q].append(p)

dfs(1, set())
print(count())

