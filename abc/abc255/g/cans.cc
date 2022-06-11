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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> X(M), Y(M);
  REP(i, M) cin >> X[i] >> Y[i];
  map<ll, vector<ll>> cstr;
  REP(i, M) cstr[X[i]].push_back(X[i] - Y[i]);
  map<ll, ll> gn, dup;
  vector<ll> red;
  ll reduce = 0;
  auto myget = [&](auto& mp, ll k, ll def) -> ll {
    auto it = mp.find(k);
    if (it == mp.end()) return def;
    return it->second;
  };
  auto grundy = [&](ll y) -> ll {
    auto it = lower_bound(ALL(red), y);
    if (it != red.end() and *it == y) return gn[y];
    ll cnt = it - red.begin();
    return y - cnt;
  };
  for (auto& [x, ys] : cstr) {
    map<ll, ll> mp;
    for (ll y : ys) {
      ll g = grundy(y);
      mp[g]++;
    }
    for (auto [m, num] : mp) {
      ll d = myget(dup, m, 1);
      if (d <= num) {
        gn[x] = m;
        red.push_back(x);
        reduce++;
        dup[m] = d + 1;
        break;
      }
    }
  }
  ll fin = 0;
  REP(i, N) fin ^= grundy(A[i]);
  cout << (fin ? "Takahashi\n" : "Aoki\n");

  return 0;
}

