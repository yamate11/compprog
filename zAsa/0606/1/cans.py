#!/usr/bin/env python3

print([y + x for x in "87654321" for (c, y) in zip(input(), "abcdefgh") if c == '*'][0])



