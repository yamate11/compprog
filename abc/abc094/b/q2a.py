#!/usr/bin/env python3

import sys
(_, m, x), aa = map(lambda x: map(int, x.split(' ')), sys.stdin)
left = len([a for a in aa if a < x])
print(min([left, m - left]))
