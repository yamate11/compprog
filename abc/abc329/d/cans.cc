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
  // @InpVec(M, A, dec=1) [3HMz8EWr]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [3HMz8EWr]

  set<pll> ss;
  vector vote(N, 0LL);
  REP(i, 0, N) ss.emplace(0, i);
  REP(i, 0, M) {
    ll j = A[i];
    ss.erase(pll(-vote[j], j));
    vote[j]++;
    ss.emplace(-vote[j], j);
    auto [_v, k] = *ss.begin();
    cout << k + 1 << "\n";
  }

  return 0;
}

