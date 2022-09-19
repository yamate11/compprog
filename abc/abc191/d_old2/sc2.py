from decimal import * 
getcontext().prec = 20
a, b, c = map(Decimal, input().split())
if a.sqrt() + b.sqrt() < c.sqrt():
	print("Yes")
else:
	print("No")
