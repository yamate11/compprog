#!/usr/bin/env python3

N = input()
S = input().strip()

if S == "BA" or (S[0] == 'A' and S[-1] == 'B'):
    print("No")
else:
    print("Yes")
    
