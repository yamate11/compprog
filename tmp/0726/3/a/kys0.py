#!/usr/bin/env python3

import sys
input = sys.stdin.readline
def iinput(): return int(input())
def sinput(): return input().rstrip()
def i0input(): return int(input()) - 1
def linput(): return list(input().split())
def liinput(): return list(map(int, input().split()))
def miinput(): return map(int, input().split())
def li0input(): return list(map(lambda x: int(x) - 1, input().split()))
def mi0input(): return map(lambda x: int(x) - 1, input().split())
INF = 10**20
MOD = 1000000007

from itertools import product
from math import floor, ceil
class SimplexMethod:
    def __init__(self, n, m):
        self.N = n
        self.M = m
        self.A = [[0 for i in range(n + m + 1)] for j in range(m + 1)]
        self.B = [0] * (m + 1)
        return

    def init_coef(self, alpha, b, c):
        self.a = alpha
        self.b = b
        self.c = c
        for i in range(self.M):
            self.B[i] = b[i]
            for j in range(self.N + self.M + 1):
                if j < self.N:
                    self.A[i][j] = alpha[i][j]
                else:
                    if j == self.N + i:
                        self.A[i][j] = 1.0
                    else:
                        self.A[i][j] = 0.0

        self.B[self.M] = 0.0
        for j in range(self.N + self.M + 1):
            if j < self.N:
                self.A[self.M][j] = -c[j]
            else:
                if j == self.N + self.M:
                    self.A[self.M][j] = -1
                else:
                    self.A[self.M][j] = 0.0

    def pivot(self):
        found_negative_gamma = False

        for j in range(self.N + self.M):
            if self.A[self.M][j] < 0.0:
                s = j
                found_negative_gamma = True
                break

        if not found_negative_gamma:
            return "done"  # FOUND SOLUTION

        found_positive_alpha = False
        for i in range(self.M):
            if self.A[i][s] > 0.0:
                found_positive_alpha = True

        if not found_positive_alpha:
            return "unbounded"  # UNBOUNDED

        v = sys.float_info.max
        for i in range(self.M):
            if self.A[i][s] > 0:
                if self.B[i]/self.A[i][s] < v:
                    v = self.B[i] / self.A[i][s]
                    r = i
        a_rs = self.A[r][s]
        for j in range(self.N + self.M):
            self.A[r][j] = self.A[r][j] / a_rs
        self.B[r] = self.B[r] / a_rs

        for i in range(self.M + 1):
            if i != r:
                a_is = self.A[i][s]
                for j in range(self.N + self.M):
                    self.A[i][j] = self.A[i][j] - self.A[r][j] * a_is
                self.B[i] = self.B[i] - self.B[r] * a_is

        return "canonical form"

    def simplex(self):
        res = self.pivot()
        if res == "unbounded":
            print("unbounded")
            return -1
        elif res == "done":
            return 1
        else:
            return self.simplex()

    def dump_matrix(self):
        for i in range(self.M + 1):
            for j in range(self.N + self.M + 1):
                print(self.A[i][j], " ", end="")
            print("  ", self.B[i])

    def get_opt_param(self, j):
        n_unity = 0
        n_nonzero = 0
        for i in range(self.M):
            if abs(self.A[i][j] - 1.0) < 1.0e-6:
                n_unity = n_unity + 1
                s = i
            elif abs(self.A[i][j]) > 1.0e-6:
                n_nonzero = n_nonzero + 1

        if n_unity == 1 and n_nonzero == 0:
            return self.B[s]
        else:
            return 0

    def get_all_opt_param(self):
        return [self.get_opt_param(i) for i in range(len(self.c))]

    def get_opt_value(self):
        return self.B[self.M]

    def check(self, X):
        for x in X:
            if x < 0:
                return False
        for i, b in enumerate(self.b):
            tmp = 0
            for j, a in enumerate(self.a[i]):
                tmp += a * X[j]
            if tmp > b:
                return False
        return True

    def objective(self, X):
        res = [c * x for c, x in zip(self.c, X)]
        return sum(res)

    def get_opt_integers_and_objective(self):
        tmp_objective = -INF
        tmp_solution = None
        opt_float = self.get_all_opt_param()
        opt_candidates = [(ceil(x), floor(x)
                           ) for x in opt_float]
        # opt_candidates = [(ceil(x) + 1, ceil(x), floor(x),
        #                    floor(x) - 1) for x in opt_float]
        for X in product(*opt_candidates):
            if self.check(X):
                tmp_objective = max(tmp_objective, self.objective(X))
                tmp_solution = X
        return tmp_objective, tmp_solution


'''
max cx
s.t. Ax <= b and x >= 0
O(row * column + (raw + column) * 2^(2 * column))
'''
row = 3
column = 5
q = SimplexMethod(column, row)
c = [1, 1, 1, 1, 1]  # size of c equals 'column'
# shape of c equals '(row, column)'
a = [[5, 2, 3, 1, 0], [0, 2, 0, 0, 2], [0, 0, 1, 2, 1]]

T = iinput()
for _ in [0] * T:
    b = liinput()
    q.init_coef(a, b, c)
    q.simplex()
    print(q.get_all_opt_param(), file=sys.stderr)
    val, sol = q.get_opt_integers_and_objective()
    print(val)
