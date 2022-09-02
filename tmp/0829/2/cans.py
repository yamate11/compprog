#!/usr/bin/env python3

lst = input().strip().split()
ans = []
for w in lst:
    if (w == "Left"):
        ans.append("<")
    elif (w == "Right"):
        ans.append(">")
    elif (w == "AtCoder"):
        ans.append("A")
    else:
        raise Exception("internal error")
print(" ".join(ans)    )

