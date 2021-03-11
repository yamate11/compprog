#!/usr/bin/env python3

import sys
import re
import os
import os.path

outlist = []

def getCont(fname):
    with open(fname) as fp:
        return [line.strip() for line in fp]

def getObj(id):
    in_cont = getCont('d' + id + '.txt')
    out_cont_file = 'do' + id + '.txt'
    if os.path.exists(out_cont_file):
        out_cont = getCont('do' + id + '.txt')
    else:
        print('*** Warning: {} does not exist. ***'.format(out_cont_file),
              file=sys.stderr, flush=True)
        out_cont = None
    return {'id': id, 'in': in_cont, 'out': out_cont}

def main():
    if len(sys.argv) <= 1:
        print('Usage: codeeg eg_id...')
        sys.exit(1)
    ids = sys.argv[1:]
    cont = [getObj(id) for id in ids]
    for obj in cont:
        out = 'inp' + obj['id'] + ' = "' + \
              ''.join([line + '\\n' for line in obj['in']]) + \
              '"'
        print(out)
    for obj in cont:
        print('tv' + obj['id'] + ' = tmain $ B.pack inp' + obj['id'])
    cont_test = [obj for obj in cont if obj['out'] is not None]
    for obj in cont_test:
        id0 = obj['id']
        print('test{} = tv{} == {}'.format(id0, id0, obj['out'][0]))
    print('alltest = ' +
          ' && '.join(['test' + obj['id'] for obj in cont_test]))

main()
