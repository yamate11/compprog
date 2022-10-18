def main():
    from sys import stdin, setrecursionlimit
    # setrecursionlimit(1000000)
    input = stdin.readline
    def iinput(): return int(input())
    def sinput(): return input().rstrip()
    def i0input(): return int(input()) - 1
    def linput(): return list(input().split())
    def liinput(): return list(map(int, input().split()))
    def miinput(): return map(int, input().split())
    def li0input(): return list(map(lambda x: int(x) - 1, input().split()))
    def mi0input(): return map(lambda x: int(x) - 1, input().split())
    INF = 1000000000000000000
    mm = 998244353937624761

    from functools import cmp_to_key
    from math import sqrt

    def f(r1, r2):
        x1, y1 = r1
        x2, y2 = r2
        return x2 * y1 - y2 * x1
    
    def cood_to_key(x, y):
        c = (x << 20) + y
        return c ^ mm

    cood = []
    xy_to_i = dict()
    N = iinput()
    for i in range(1, N+1):
        x, y = miinput()
        cood.append((x, y))
        xy_to_i[cood_to_key(x, y)] = i
    cood.sort(key=cmp_to_key(f))
    cood_1 = []
    cood_2 = []

    for x, y in cood:
        if y == 0:
            if x > 0:
                cood_1.append((x, y))
            else:
                cood_2.append((x, y))
        elif y > 0:
            cood_1.append((x, y))
        else:
            cood_2.append((x, y))
    cood = cood_1 + cood_2
    cood.append(cood[0])
    ans = -1.1
    for (x1, y1), (x2, y2) in zip(cood, cood[1:]):
        c = (x1 * x2 + y1 * y2) / (sqrt(x1 ** 2 + y1 ** 2) * sqrt(x2 ** 2 + y2 ** 2))
        if c > ans:
            tmp = (x1, y1, x2, y2)
            ans = c
    x1, y1, x2, y2 = tmp
    print(xy_to_i[cood_to_key(x1, y1)], xy_to_i[cood_to_key(x2, y2)])
main()
