#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
  #define DFUNC(fname, ...) fname(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFUNC(fname, ...)
#endif

ll r,D,x0;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> r >> D >> x0;

  ll x = x0;
  for (ll i = 1; i <= 10; i++) {
    x = r * x - D;
    cout << x << endl;
  }

  return 0;
}

