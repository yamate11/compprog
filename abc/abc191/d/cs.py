from decimal import Decimal
getcontext().prec = 20
a, b, c = map(Decimal, input().split())
if a ** Decimal('0.5') + b ** Decimal('0.5') < c ** Decimal('0.5'):
	print("Yes")
else:
	print("No")
