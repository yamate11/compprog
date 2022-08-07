#!/usr/bin/env python3

K = int(input())
h = K // 60
m = K % 60
h += 21
print(f'{h:02d}:{m:02d}')
