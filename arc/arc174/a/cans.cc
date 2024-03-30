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

  ll N, C; cin >> N >> C;
  // @InpVec(N, A) [Za0h2xAQ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Za0h2xAQ]

  vector<ll> S(N + 1);
  REP(i, 0, N) S[i + 1] = S[i] + A[i];

  if (C > 0) {
    ll diff = 0;
    ll vmin = 0;
    REP(i, 1, N + 1) {
      diff = max(diff, S[i] - vmin);
      vmin = min(vmin, S[i]);
    }
    cout << S[N] + diff * (C - 1) << endl;
  }else {
    ll diff = 0;
    ll vmax = 0;
    REP(i, 1, N + 1) {
      diff = min(diff, S[i] - vmax);
      vmax = max(vmax, S[i]);
    }
    cout << S[N] + diff * (C - 1) << endl;
  }

  return 0;
}

