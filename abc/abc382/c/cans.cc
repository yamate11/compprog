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
  // @InpVec(N, A) [A571NKDy]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [A571NKDy]
  // @InpVec(M, B) [vU767xGX]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [vU767xGX]

  ll big = 1e18;
  vector<ll> AA(N);
  {
    ll v = big;
    REP(i, 0, N) {
      v = min(v, A[i]);
      AA[i] = -v;
    }
  }
  REP(i, 0, M) {
    ll j = lower_bound(ALL(AA), -B[i]) - AA.begin();
    if (j == N) {
      cout << -1 << "\n";
    }else {
      cout << j + 1 << "\n";
    }
  }
  

  return 0;
}

