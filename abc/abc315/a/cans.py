#!/usr/bin/env python3

S = input()
ans = ""
for c in S:
    if c not in "aeiou":
        ans += c
print(ans)

