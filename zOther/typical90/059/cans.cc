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

  ll N, M, Q; cin >> N >> M >> Q;
  vector<vector<ll>> nbr(N + 100);
  for (ll i = 0; i < M; i++) {
    ll x, y; cin >> x >> y; x--; y--;
    nbr[x].push_back(y);
  }
  uint64_t zero = 0;
  uint64_t one = 1;
  vector<ll> A(Q), B(Q);
  for (ll t = 0; t < Q; t++) {
    ll a, b; cin >> a >> b; a--; b--;
    A[t] = a;
    B[t] = b;
  }
  ll t = 0;
  while (t < Q) {
    vector rec(N, zero);
    ll m = (t + 64 <= Q) ? 64 : Q - t;
    for (ll i = 0; i < m; i++) {
      rec[A[t + i]] |= one << i;
    }
    auto reach = vector(N, zero);
    for (ll j = 0; j < N; j++) {
      reach[j] |= rec[j];
      for (ll x : nbr[j]) { reach[x] |= reach[j]; }
    }
    for (ll i = 0; i < m; i++) {
      if ((reach[B[t + i]] >> i) & 1) cout << "Yes\n";
      else cout << "No\n";
    }
    t += m;
  }
  return 0;
}

