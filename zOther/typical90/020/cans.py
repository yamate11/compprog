#!/usr/bin/env python3

a, b, c = map(int, input().strip().split())
print("Yes" if a < c ** b else "No")
