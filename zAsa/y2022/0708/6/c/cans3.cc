#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

#define EXISTS(i, from, to, cond) ([&](){for (ll i = from; i < to; i++) if (cond) return true; return false; }())

ll naive(ll m, ll n) {
  ll ret = 0;
  vector vec(m, vector(n, 0LL));
  auto dfs = [&](auto rF, ll i, ll j) -> void {
    if (i == m) { ret++; return; }
    for (ll t = 1; t <= 3; t++) {
      if (EXISTS(p, max(0LL, i - t), i, vec[p][j] == t) or
          EXISTS(q, max(0LL, j - t), j, vec[i][q] == t)) continue;
      vec[i][j] = t;
      rF(rF, i + (j + 1) / n, (j + 1) % n);
    }
  };
  dfs(dfs, 0, 0);
  return ret;
}

ll diagonal(ll len) {
  static const vector<ll> pat{1, 2, 2, 1};
  ll ret = 0;
  for (ll i = 0; i < 4; i++) ret += pat[i] * pat[(len - 1 - i) % 4];
  return ret;
}

int main() {
  ll M, N; cin >> M >> N;
  if (M > N) swap(M, N);
  ll ans = (N <= 10) ? naive(M, N)
         : (M == 1)  ? diagonal(N)
         :             2 * diagonal(N + M - 1);
  cout << ans << endl;
  return 0;
}

