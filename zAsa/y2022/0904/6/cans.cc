#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((X, dec=1), (Y, dec=1), Z)) [N0cc4uav]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  auto Z = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [N0cc4uav]
  vector<ll> tbl_init(1LL << N);
  auto tbl = tbl_init;
  tbl[0] = 1;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(x, 0, 1LL << N) {
      if (prev[x] == 0 or __builtin_popcountll(x) != i) continue;
      REP(j, 0, N) {
        if (x >> j & 1) continue;
        ll y = x | (1LL << j);
        tbl[y] += prev[x];
      }
    }
    REP(x, 0, 1LL << N) {
      if (__builtin_popcountll(x) != i + 1) continue;
      REP(k, 0, M) {
        if (X[k] != i) continue;
        ll mask = (1 << (Y[k] + 1)) - 1;
        if (__builtin_popcountll(mask & x) > Z[k]) tbl[x] = 0;
      }
    }
  }
  ll ans = 0;
  REP(x, 0, 1LL << N) ans += tbl[x];
  cout << ans << endl;

  return 0;
}

