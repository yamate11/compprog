#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using sta = pair<ll, ll>;

  auto func = [&](auto& X, auto& Y, auto& P) -> ll {
    ll ret = 0;
    sort(ALL(P));
    ll j = 0;
    ll szX = SIZE(X);
    ll szP = SIZE(P);
    for (ll i = 0; i + 1 < szX; i++) {
      map<ll, ll> mp;
      while (j < szP && P[j].first <= X[i]) j++;
      while (j < szP && P[j].first < X[i + 1]) {
        ll y = P[j].second;
        mp[y]++;
        j++;
      }
      ll a1 = 0;
      ll a2 = 0;
      for (auto [y, n] : mp) {
        a1 += n;
        a2 += n * n;
      }
      ret += ((a1 * a1) - a2) / 2;
    }
    return ret;
  };

  auto solve = [&]() -> void {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> X(N), Y(M);
    REP(i, N) cin >> X[i];
    REP(i, M) cin >> Y[i];
    vector<sta> P(K);
    REP(i, K) cin >> P[i].first >> P[i].second;
    ll a1 = func(X, Y, P);
    REP(i, K) {
      auto [x, y] = P[i];
      P[i] = {y, x};
    }
    ll a2 = func(Y, X, P);
    cout << a1 + a2 << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

