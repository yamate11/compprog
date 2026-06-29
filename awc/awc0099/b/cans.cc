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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, (S, R)) [e9iSdtuG]
  auto S = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [e9iSdtuG]
  // @InpVec(N, T) [A5PVHxtH]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [A5PVHxtH]
  vector<pll> RS(M);
  REP(i, 0, M) RS[i] = pll(R[i], S[i]);
  ranges::sort(RS);
  vector<ll> smx(M + 1, 0LL);
  REP(i, 0, M) smx[i + 1] = max(smx[i], RS[i].second);

  ll ans = 0;
  REP(i, 0, N) {
    auto j0 = ranges::lower_bound(RS, pll(T[i] + 1, -1LL)) - RS.begin();
    ans += smx[j0];
  }
  cout << ans << endl;
  return 0;
}

