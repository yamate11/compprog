#!/usr/bin/env python3

S = input()
x, _, z = sorted([S.count(c) for c in "abc"])
print("YES" if z <= x + 1 else "NO")
