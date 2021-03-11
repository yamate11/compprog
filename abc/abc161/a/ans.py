#!/usr/bin/env python3

(x, y, z) = input().strip().split()
(x,y) = (y,x)
(x,z) = (z,x)
print('{} {} {}'.format(x, y, z))
