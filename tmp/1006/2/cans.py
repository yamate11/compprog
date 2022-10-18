#!/usr/bin/env python3

import re

S = input()
mo = re.match(r'.*?(\d+)', S)
print(mo[1])
