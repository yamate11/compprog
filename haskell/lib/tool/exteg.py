#!/usr/bin/env python3

import sys, re, os, argparse

outlist = []

def out(fp, type, id, fst_line):
    ofname = ('d' if type == '入' else 'do') + id + '.txt'
    if not args.force and os.path.exists(ofname):
        print('File ' + ofname + ' exists.  Consider -f.  Abort.\n',
              file=sys.stderr)
        sys.exit(1)
    cont = fst_line + '\n'
    for line in fp:
        if line.startswith('</pre>'):
            break
        cont += line.strip() + '\n'
    outlist.append({'name': ofname, 'cont': cont})

def main():
    global args
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--force', action='store_true',
                        help='force overwrite')
    parser.add_argument('file')
    args = parser.parse_args()
    ids = []
    with open(args.file) as fp:
        for line in fp:
            mo = re.match(r'<h3>(入|出)力例\s*(\d+).*?<pre.*?>(.*)',
                          line.strip())
            if mo:
                if mo.group(1) == '入':
                    ids.append(mo.group(2))
                out(fp, *mo.group(1,2,3))
    for d in outlist:
        with open(d['name'], 'w') as wfp:
            print(d['cont'], file=wfp, end='')
    print(' '.join(ids))

main()
