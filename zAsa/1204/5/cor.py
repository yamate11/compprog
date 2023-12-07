#!/usr/bin/env python3

import re, sys

def fromCamel(x):
    if not x[0].islower():
        return None
    lst = re.findall(r'(?:^[a-z]|[A-Z])[a-z0-9]*', x)
    return [w[0].lower() + w[1:] for w in lst] if ''.join(lst) == x else None

def fromSnake(x):
    lst = x.split('_')
    return lst if all([re.match(r'[a-z][a-z0-9]*$', w) for w in lst]) else None

def body(s):
    if s == '':
        return ''
    elif (lst := fromCamel(s)) is not None:
        return '_'.join(lst)
    elif (lst := fromSnake(s)) is not None:
        return lst[0] + ''.join([w[0].upper() + w[1:] for w in lst[1:]])
    else:
        return s

mo = re.match(r'(_*)(.*?)(_*)$', input().strip())
print(mo[1] + body(mo[2]) + mo[3])

