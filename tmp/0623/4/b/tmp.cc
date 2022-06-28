FORALL(i, N, FORALL(j, M, a[i] * b[j] < C))


([&]() -> {
  for (ll i = 0; i < (N); i++)  if (not (a[i] * a[i] < C)) return false;
  return true;
 }())


FIND(i, N, -1, func(i) == 0)
  

([&]() -> {
  for (ll i = 0; i < (N); i++) if (func(i) == 0) return i;
  return (-1);
 }())
