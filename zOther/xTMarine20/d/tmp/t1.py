#!/usr/bin/env python3

import argparse, subprocess, os, sys


def main():
    with subprocess.Popen(
            ['./foo'], encoding='UTF-8',
            stdin=subprocess.PIPE, stdout=subprocess.PIPE) as pr:
        print("10", file=pr.stdin, flush=True)
        line = pr.stdout.readline()
        print(line.strip())
        print("1", file=pr.stdin, flush=True)
        line = pr.stdout.readline()
        if line == '':
            print('Unexpected behavior')
            return
        print(line)
        print("-1", file=pr.stdin, flush=True)



main()

    
