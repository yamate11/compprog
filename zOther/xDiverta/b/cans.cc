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

ll R, G, B, N;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> R >> G >> B >> N;

  ll cnt = 0;
  for (ll r = 0; r <= N / R; r++) {
    ll rem = N - r * R;
    for (ll g = 0; g <= rem / G; g++) {
      ll rem2 = rem - g * G;
      if (rem2 % B == 0)  cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}

