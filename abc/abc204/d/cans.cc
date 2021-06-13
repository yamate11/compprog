#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll tot = 0;
  vector<ll> T(N);
  for (ll i = 0; i < N; i++) {
    ll t; cin >> t;
    T[i] = t;
    tot += t;
  }
  ll half = tot / 2;
  auto cur = vector<bool>(half + 1);
  cur[0] = true;
  for (ll i = 0; i < N; i++) {
    auto prev(cur);
    for (ll t = 0; t <= half - T[i]; t++) {
      if (!prev[t]) continue;
      cur[t + T[i]] = true;
    }
  }
  for (ll t = half; t >= 0; t--) {
    if (cur[t]) {
      cout << tot - t << endl;
      return 0;
    }
  }


  return 0;
}

