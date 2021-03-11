#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll N;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N;
  ll max = 0;
  ll count = 0;
  for (ll i = 0; i < N; i++) {
    ll h;
    cin >> h;
    if (max <= h) {
      count++;
      max = h;
    }
  }
  cout << count << endl;
  return 0;
}

