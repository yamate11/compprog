#!/usr/bin/env python3


def binom(n, r):
    ret = 1.0
    for i in range(r):
        ret *= (n - i) / (r - i);
    return ret

prob = 0.8
n = 50
ans = 0.0
for i in range((n + 1) // 2, n + 1):
    ans += binom(n, i) * prob ** i * (1.0 - prob) ** (n - i)
print(ans)

    
