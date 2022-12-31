#!/usr/bin/env python3

import re

S = input().rstrip()
t = re.sub(r' +', ',', S)
print(t)
