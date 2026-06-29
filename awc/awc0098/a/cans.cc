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

  ll N, D; cin >> N >> D;
  // @InpVec(N, T) [xhC8Xpk0]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [xhC8Xpk0]
  // @InpGrid(N, D, A) [aASF86VA]
  auto A = vector(N, vector(D, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < D; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [aASF86VA]
  vector<ll> S(N, 0LL);
  REP(i, 0, N) {
    REP(j, 0, D) {
      S[i] += abs(A[i][j] - T[i]);
    }
  }
  ll ans = *ranges::max_element(S);
  cout << ans << endl;


  return 0;
}

