#!/usr/bin/env python3

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--aaa-bb', type=int)
args = parser.parse_args()

print(args.aaa_bb + 1)
