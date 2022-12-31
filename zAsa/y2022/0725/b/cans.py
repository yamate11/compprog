#!/usr/bin/env python3

def parse(s):
    ret = []
    i = 0
    while i < len(s):
        l = 3 if s[i + 1] == '1' else 2
        ret.append((s[i], s[i + 1] in 'A1JQK', s[i:(i+l)]))
        i += l
    return ret

def getSuite(inp):
    mp = {c : 0 for c in 'SHDC'}
    for i in range(len(inp)):
        (suit, effective, _) = inp[i]
        if effective:
            mp[suit] += 1
            if mp[suit] == 5:
                return (suit, i + 1)

inp = parse(input().rstrip())
(suit, l) = getSuite(inp)
ans = ''
for [s, effective, face] in inp[:l]:
    if not (s == suit and effective):
        ans += face
print(ans or '0')


