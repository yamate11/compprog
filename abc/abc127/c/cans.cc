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

ll N, M;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> M;
  ll left = 1;
  ll right = N;
  for (ll i = 0; i < M; i++) {
    ll l, r;
    cin >> l >> r;
    if (left < l)  left = l;
    if (r < right)  right = r;
  }
  ll answer = max(0LL, right - left + 1);
  cout << answer << endl;

  return 0;
}

