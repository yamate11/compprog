#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  auto func1 = [&](ll x, const auto& v) -> pair<ll, ll> {
    REP(j, SIZE(v)) if ((x = min(x, x ^ v[j].second)) == 0) return {j, 0};
    return {-1, x};
  };

  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  using sta = pair<ll, ll>;
  vector<vector<sta>> B(N);

  REP(i, N) {
    B[i].emplace_back(i, A[i]);
    if (i == 0) continue;
    ll sz = SIZE(B[i - 1]);
    ll j0 = [&]() -> ll {
      REP(j, sz) {
        auto [p, y] = B[i - 1][j];
        auto [k, x] = func1(y, B[i]);
        if (k < 0)  B[i].emplace_back(p, x);
        else        return j + 1;
      }
      return sz;
    }();
    REP2(j, j0, sz) B[i].push_back(B[i - 1][j]);
  }

  REP(i, Q) {
    ll l, r, x; cin >> l >> r >> x; l--; r--;
    auto [j, dummy] = func1(x, B[r]);
    cout << (j >= 0 && l <= B[r][j].first ? "Yes\n" : "No\n");
  }
  return 0;
}

