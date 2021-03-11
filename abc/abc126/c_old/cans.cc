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

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> K;

  ll top = N+1;
  ll bot = K;
  double sum = 0.0;
  double p = 1.0;
  while (top > 1) {
    ll num = min(N+1, top) - bot;
    if (num > 0) {
      sum += (double)num / N * p;
    }
    top = bot;
    bot = (top + 1) >> 1;
    p *= 0.5;
  }
  cout << setprecision(15) << sum << endl;

  return 0;
}

