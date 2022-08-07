n,x=map(int,input().split())
if x==1 or x==2*n-1:
  print("No")
  exit()
l=[i+1 for i in range(2*n+1)]
if x==2:
  l.remove(x-1)
  l.remove(x)
  l.remove(x+1)
  l.remove(x+2)
  print("Yes")
  for i in range(n-1):
    print(l[i])
  print(x+2)
  print(x)
  print(x-1)
  print(x+1)
  for i in range(n+3,len(l)):
    print(l[i])
else:
  l.remove(x-1)
  l.remove(x)
  l.remove(x+1)
  l.remove(x-2)
  print("Yes")
  for i in range(n-1):
    print(l[i])
  print(x-1)
  print(x)
  print(x+1)
  print(x-2)
  for i in range(n+3,len(l)):
    print(l[i])
