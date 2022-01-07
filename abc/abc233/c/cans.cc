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

  ll N, X; cin >> N >> X;
  vector<vector<ll>> L(N);
  REP(i, N) {
    ll l; cin >> l;
    L[i] = vector<ll>(l);
    REP(j, l) cin >> L[i][j];
  }
  map<ll, ll> mp_init;
  auto mp = mp_init;
  mp[1] = 1;
  REP(i, N) {
    auto prev = move(mp);
    mp = mp_init;
    for (auto& [v, n] : prev) {
      for (ll w : L[i]) {
        if (w > X / v) continue;
        mp[v * w] += n;
      }
    }
  }
  cout << mp[X] << endl;

  return 0;
}

