#!/usr/bin/env python3

import sys

sys.set_int_max_str_digits(10000)

def goodrep(x):
    y = str(10 ** 5000 // x)
    if y[:x - 1] == y[x - 1:2 * (x - 1)]:
        for i in range(1, x - 1):
            if y[:10] == y[i:i + 10]:
                return None
        return y[:x - 1]
    return None

# x = 1001
# while True:
#     y = goodrep(x)
#     if y is not None:
#         break
#     x += 1
# print(x)
# print(y)
# print(int(y) * 11)

x = 1019
t = int(goodrep(x)[:-3])

st = str(t)
cand = st + '000' + st
for i in range(1, 1001):
    # print(i, end=' ')
    sv = str(t * i)
print(st)
print(cand)

# sw = str(t * 999)
# print(st)
# print(str(t*2))
# print(sv)
# print(sw)
# i = st.index(sw[:10])
# print(f'i={i}')
# len1 = len(st) - i
# if sw[:len1] == st[i:]:
#     print('same')
# else:
#     print('diff')

# print(len(st), len(sw), st[:i] == sw[len1+3:])
