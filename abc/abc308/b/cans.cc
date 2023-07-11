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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpVec(N, C, type=string) [DO9ioxrv]
  auto C = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; C[i] = v; }
  // @End [DO9ioxrv]
  vector<string> D(M + 1);
  REP(i, 1, M + 1) cin >> D[i];
  // @InpVec(M + 1, P) [4m2biGtl]
  auto P = vector(M + 1, ll());
  for (int i = 0; i < M + 1; i++) { ll v; cin >> v; P[i] = v; }
  // @End [4m2biGtl]

  map<string, ll> mp;
  REP(i, 1, M + 1) mp[D[i]] = P[i];
  ll ans = 0;
  REP(i, 0, N) {
    auto it = mp.find(C[i]);
    if (it == mp.end()) ans += P[0];
    else ans += it->second;
  }
  cout << ans << endl;

  return 0;
}

