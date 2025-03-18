#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
for line in lines:
    assert line[-1] == '\n'
assert len(lines) == 4
for line in lines:
    assert ' '.join(line.strip().split()) + '\n' == line
for line in lines:
    for w in line.strip().split():
        x = int(w)
        assert f'{x}' == w

N, M, K = map(int, lines[0].strip().split())
S = list(map(int, lines[1].strip().split()))
A = list(map(int, lines[2].strip().split()))
B = list(map(int, lines[3].strip().split()))

assert len(lines[0].strip().split()) == 3
assert len(S) == N
assert len(A) == M
assert len(B) == M

assert 1 <= N and N <= 2000
for s in S:
    assert 1 <= s and s <= M and M <= 2000
for a in A:
    assert 1 <= a and a <= K and K <= 2000
for b in B:
    assert 1 <= b and b <= K
    
