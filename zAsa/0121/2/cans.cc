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
  // @InpVec(N, S, type=string) [l2NnFqzt]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [l2NnFqzt]
  ll M; cin >> M;
  // @InpVec(M, T, type=string) [xPsEzSNY]
  auto T = vector(M, string());
  for (int i = 0; i < M; i++) { string v; cin >> v; T[i] = v; }
  // @End [xPsEzSNY]
  map<string, ll> mpS, mpT;
  REP(i, 0, N) mpS[S[i]]++;
  REP(i, 0, M) mpT[T[i]]++;
  ll ans = 0;
  for (auto [s, n] : mpS) ans = max(ans, n - mpT[s]);
  cout << ans << endl;


  return 0;
}

