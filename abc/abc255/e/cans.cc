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

  ll N, M; cin >> N >> M;
  vector<ll> S(N - 1); REP(i, N - 1) cin >> S[i];
  vector<ll> X(M); REP(i, M) cin >> X[i];
  map<ll, ll> even, odd;
  even[0] = 1;
  ll a = 0;
  REP2(i, 1, N) {
    a = S[i - 1] - a;
    if (i % 2 == 1) odd[a]++;
    else            even[a]++;
  }
  auto myget = [&](map<ll, ll>& mp, ll z) -> ll {
    auto it = mp.find(z);
    if (it == mp.end()) return 0;
    return it -> second;
  };

  vector shift(M, map<ll, ll>());
  set<ll> cands;
  REP(i, M) {
    // ll base = myget(odd, X[i]) + myget(even, X[i]);
    // shift[i][0] = base;
    for (auto [p, cnt] : even) {
      shift[i][X[i] - p] = cnt;
      cands.insert(X[i] - p);
    }
    for (auto [p, cnt] : odd) {
      shift[i][p - X[i]] += cnt;
      cands.insert(p - X[i]);
    }
  }
  ll ans = 0;
  for (ll c : cands) {
    ll val = 0;
    REP(i, M) val += myget(shift[i], c);
    ans = max(ans, val);
  }
  cout << ans << endl;

  return 0;
}

