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
  // @InpVec(N, S, type=string) [EweiAtnm]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [EweiAtnm]
  // @InpVec(M, T, type=string) [RG9nZImd]
  auto T = vector(M, string());
  for (int i = 0; i < M; i++) { string v; cin >> v; T[i] = v; }
  // @End [RG9nZImd]
  set<string> ss;
  REP(i, 0, M) ss.insert(T[i]);
  REP(i, 0, N) {
    if (ss.find(S[i]) != ss.end()) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}

