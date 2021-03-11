#!/usr/bin/env python3

import subprocess, sys

def operate():
    with open('tmp.txt', 'w') as fp:
        subprocess.run(["./gen.py", "1000"], stdout=fp)
    with open('tmp.txt') as fp:
        cp = subprocess.run(["./ans"], stdin=fp)
    rc = cp.returncode
    if rc != 0:
        print('rc = {}'.format(rc), file=sys.stderr)
        sys.exit(1)

for i in range(100):
    operate()
