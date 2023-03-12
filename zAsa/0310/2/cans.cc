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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [ezrE7L63]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [ezrE7L63]
  ll M; cin >> M;
  // @InpVec(M, T, type=string) [6HWB45VP]
  auto T = vector(M, string());
  for (int i = 0; i < M; i++) { string v; cin >> v; T[i] = v; }
  // @End [6HWB45VP]
  ll ans = 0;
  REP(i, 0, N) {
    ll t = 0;
    REP(j, 0, N) if (S[i] == S[j]) t++;
    REP(j, 0, M) if (S[i] == T[j]) t--;
    ans = max(ans, t);
  }
  cout << ans << endl;

  return 0;
}

