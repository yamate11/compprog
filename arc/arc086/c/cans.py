#!/usr/bin/env python3

N, K = map(int, input().strip().split())
A = map(int, input().strip().split())

# dic = {}
# for a in A:
#     if a in dir:
#         dir[a] = 0
#     dir[a] += 1

count = [0 for i in range(N + 1)]
for a in A:
    count[a] += 1
count.sort(reverse=True)
print(N - sum(count[:K]))

    
