#!/usr/bin/env python3

import sys
import os
import subprocess
import requests

if sys.version_info < (3, 6):
    print('Sorry, python should be 3.6 or later.  Yours is '
          + sys.version_info, file=sys.stderr)
    sys.exit(1)

class MyException(Exception):
    pass

srcdir = os.path.dirname(os.path.realpath(__file__))
qfile = 'q.html'
skelfile = 'ans.hs'

# Ask user to choose from options
# prompt: prompt
# options: list of (str, func)
#   str should contain exactly one upper case letter, that should not
#   be overlapped through options.  The letter will be the key.
#   func will run when the option is chosen, and its return value is returned.
# default: an index of options or None
def userChoice(prompt, options, default):
    def findKey(s, isDef):
        for j in range(len(s)):
            if s[j].isupper():
                os = s[:j] + '[' + s[j] + ']' + s[j+1:] if isDef else s
                return (s[j], os)
        assert False

    key = []
    optStrList = []
    for i,(s,_) in enumerate(options):
        (k, os) = findKey(s, i == default)
        key.append(k)
        optStrList.append(os)
    optStr = '/'.join(optStrList)

    while True:
        xx = input(f'{prompt} ({optStr})? ')
        x = xx[0].upper() if xx else '' if default is None else key[default]
        try:
            (_, f) = options[key.index(x)]
            return f()
        except ValueError:
            continue

# Asks Yes/No question.  Returns True/False
# default  0 .. Yes, 1 .. No, None .. no default
def userYN(prompt, default):
    return userChoice(prompt, [('Y', lambda: True), ('N', lambda: False)],
                      default)

def confow():
    if os.path.exists(skelfile):
        return userChoice(f'{skelfile} exists.',
                          [('Ren', lambda: True),
                           ('Abt', lambda: sys.exit(1)),
                           ('Ow',  lambda: False)],
                          0)
    else:
        return False

def rename_skel():
    for i in range(100):
        name = f'bup.{skelfile}.{i:02d}'
        if not os.path.exists(name):
            break
    else:
        print('Sorry, rename failed.', file=sys.stderr)
        sys.exit(1)
    os.rename(skelfile, name)

def prepareQfile():
    if os.path.exists(qfile) \
       and userYN(f'{qfile} exists.  Do you use it', 0):
        return True
    while True:
        url = input('question url (or empty RET): ')
        if url:
            r = requests.get(url)
            if r.status_code != 200:
                print('Failed to get question file.', file=sys.stderr)
                continue
            r.encoding = 'utf-8'
            with open(qfile, 'w', encoding='utf-8') as fp:
                print(r.text, file=fp)
            return True
        if userYN('Skip generating tests', 0):
            return False
    
def checkcp(cp, name):
    if cp.returncode != 0:
        raise MyException(f'{name} failed.')

def genSkel(inspec, outspec, renP):
    cp = subprocess.run([srcdir + '/mkskel', inspec, outspec],
                        encoding='utf-8', stdout=subprocess.PIPE)
    checkcp(cp, 'mkskel')
    if renP:
        rename_skel()
    with open(skelfile, 'w', encoding='utf-8') as wfp:
        print(cp.stdout, file=wfp)

def genTest():
    cp = subprocess.run([srcdir + '/exteg.py', '-f', qfile],
                        encoding='utf-8', stdout=subprocess.PIPE)
    checkcp(cp, 'exteg')

    qids = cp.stdout.split()
    cp = subprocess.run([srcdir + '/codeeg.py'] + qids,
                        encoding='utf-8', stdout=subprocess.PIPE)
    with open(skelfile, 'a', encoding='utf-8') as wfp:
        print(f'{"-" * 79}\n', file=wfp)
        print(cp.stdout, file=wfp)

def nonEmptyInput(prompt):
    while True:
        x = input(prompt)
        if x:
            return x

def main():
    renP = confow()
    inspec = nonEmptyInput('inspec: ')
    outspec = nonEmptyInput('outspec: ')
    genTestP = prepareQfile()
    try:
        genSkel(inspec, outspec, renP)
        if genTestP:
            genTest()
    except MyException as e:
        print(e)
        sys.exit(1)

main()
