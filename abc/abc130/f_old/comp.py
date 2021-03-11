#!/usr/bin/env python3


import subprocess

def foo():
    with open('d9.txt', 'w', encoding='UTF-8') as fp:
        cp = subprocess.run(["./gen.py"], stdout=fp)

    with open('d9.txt', encoding='UTF-8') as fp:
        cp1 = subprocess.run(["./other2.py"], stdin=fp, stdout=subprocess.PIPE)

    with open('d9.txt', encoding='UTF-8') as fp:
        cp2 = subprocess.run(["./cans"], stdin=fp, stdout=subprocess.PIPE)

    return abs(float(cp1.stdout) - float(cp2.stdout)) < 0.00000000001

for i in range(100):
    if not foo():
        print("Failed")
        break

