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

  ll T, N; cin >> T >> N;
  // @InpGrid(T, N, P) [POasdM0h]
  auto P = vector(T, vector(N, ll()));
  for (int i = 0; i < T; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; P[i][j] = v; }
  // @End [POasdM0h]
  
  vector C(N, 0LL);
  REP(t, 0, T) {
    REP(i, 0, N) C[i] = max(C[i], P[t][i]);
    cout << accumulate(ALL(C), 0LL) << "\n";
  }

  return 0;
}

