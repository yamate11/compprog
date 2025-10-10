#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, P) [HzgGbiDp]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [HzgGbiDp]
  // @InpVec(N, C) [MJ5EnhPL]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [MJ5EnhPL]

  vector<vector<ll>> vec(N + 1);
  REP(i, 0, N) {
    vec[C[i]].push_back(P[i]);
  }
  ll cnt = 0;
  auto f = [&](auto& V) -> ll {
    ll m = ssize(V);
    vector<ll> tbl;
    REP(i, 0, m) {
      ll j = lower_bound(ALL(tbl), V[i]) - tbl.begin();
      if (j == ssize(tbl)) tbl.push_back(V[i]);
      else tbl[j] = V[i];
    }
    return m - ssize(tbl);
  };

  REP(i, 0, N + 1) cnt += i * f(vec[i]);
  cout << cnt << endl;

  return 0;
}

