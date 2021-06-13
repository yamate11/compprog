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

  ll N, Q; cin >> N >> Q;
  vector<ll> d(N - 1);
  ll val = 0;
  ll prev = 0;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (i >= 1) {
      d[i - 1] = a - prev;
      val += abs(d[i - 1]);
    }
    prev = a;
  }
  for (ll q = 0; q < Q; q++) {
    ll l, r, v; cin >> l >> r >> v;
    if (l >= 2) {
      ll nh = d[l - 2] + v;
      val += abs(nh) - abs(d[l - 2]);
      d[l - 2] = nh;
    }
    if (r < N) {
      ll nh = d[r - 1] - v;
      val += abs(nh) - abs(d[r - 1]);
      d[r - 1] = nh;
    }
    cout << val << "\n";
  }

  return 0;
}

