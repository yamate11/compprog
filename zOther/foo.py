#!/usr/bin/env python3

import sys, re

info = {}
for fpath in sys.stdin:
    mo = re.match(r'(.*?)/', fpath)
    key = mo[1]
    if key not in info:
        info[key] = set()
    fpath = fpath.strip()
    with open(fpath) as fp:
        cont = ''.join(fp.readlines())
        for mo in re.finditer(r'/contests/([^/"\']*)/', cont):
            # print('*** ', mo[1])
            info[key].add(mo[1])
for k in info:
    if len(info[k]) == 1:
        for x in info[k]:
            print(k, x)
        

