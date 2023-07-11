#!/usr/bin/env python3

import re

def main():
    print(['Yes', 'No'][re.fullmatch(r'(wa|w\?|\?a|wo|\?o|n|\?)+', input()) is None])
        
main()
