#!/usr/bin/env python3

def tolist(n):
    res = []
    for i in range(5):
        res.append(1 + n % 5)
        n //= 5
    return res

def chk(lst):
    for i in range(4):
        if lst[i] > 1:
            for j in range(2, lst[i] + 1):
                if i + j < 5 and lst[i + 1] != lst[i + j]:
                    return False
    return True

def classify(lst):
    def haveOne():
        for j in range(lst[i]):
            if i + 1 + j < 5 and lst[i + 1 + j] == 1:
                continue
            return False
        return True

    i = 0
    while i < 5:
        if lst[i] == 1:
            i += 1
        else:
            if not haveOne():
                return i
            i += lst[i]
    return 5

def main():
    cnt = [0] * 6
    for i in range(5*5*5*5*5):
        lst = tolist(i)
        if not chk(lst):
            continue
        t = classify(lst)
        cnt[t] += 1
    print(cnt)

main()

