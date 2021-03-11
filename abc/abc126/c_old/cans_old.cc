#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 1

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll N, K;

long double dmax(long double x, long double y) {
  if (x < y) { return y; }
  else { return x; }
}

ll ceilJ(ll j) {
  ll pow = 1 << j;
  return min(N+1, (K + (pow-1)) / pow);
}

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;

  long double sum = dmax(0.0, (long double)(N+1 - K) / (long double)N);
  long double p = 0.5;
  for (ll j = 1; 1; j++) {
    long double thisX = (long double)(ceilJ(j-1) - ceilJ(j)) / (long double)N;
    if (ceilJ(j) == 1 && ceilJ(j-1) == 1) break;
    long double thisY = p * thisX;
    DLOG("%lld, %Lf, %Lf\n", j, thisX, thisY);
    sum += thisY;

    p *= 0.5;
  }
  printf("%5.18Lf\n", sum);
  return 0;
}

