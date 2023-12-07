#!/usr/bin/env python3

import re


def isWord(s):
    mo = re.match(r'[a-z][a-z0-9]*$', s)
    if mo:
        return True
    else:
        return False

def capit(s):
    return s[0].upper() + s[1:]


def func(s):
    if '_' in s:
        ws = list(s.split('_'))
        if all(map(isWord, ws)):
            return ws[0] + ''.join(map(capit, ws[1:]))
        else:
            return s
    mo = re.match(r'([a-z][a-z0-9]*)(.*)', s)
    if (not mo):
        return s
    words = [mo[1]]
    t = mo[2]
    while t != '':
        if not t[0].isupper():
            return s
        mo = re.match(r'([A-Z][a-z0-9]*)(.*)', t)
        u = mo[1]
        words.append(u[0].lower() + u[1:])
        t = mo[2]
    return '_'.join(words)

def main():
    S = input()
    if S == '_':
        print(S)
        return
    a = False
    b = False
    if S[0] == '_':
        a = True
        S = S[1:]
    if S[-1] == '_':
        b = True
        S = S[:-1]
    t = func(S)
    if a:
        t = '_' + t
    if b:
        t += '_'
    print(t)

main()
