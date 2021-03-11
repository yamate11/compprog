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
string S;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> S;
  ll white = 0;
  for (ll i = 0; i < N; i++) {
    if (S.at(i) == '.')  white++;
  }
  ll ans = white;
  ll cur = white;
  for (ll i = 0; i < N; i++) {
    if (S.at(i) == '.')  cur--;
    else                 cur++;
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

