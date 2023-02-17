#!/usr/bin/env python3

4 Integer Cards

```python
N, M = map(int, input().split())
vec = [(a, 1) for a in map(int, input().split())]
vec += [(c, b) for (b, c) in [map(int, input().split()) for _ in range(M)]]
vec.sort(reverse=True)
ans = 0
n = 0
for (c, b) in vec:
    k = min(b, N - n)
    ans += c * k
    n += k
print(ans)
```


