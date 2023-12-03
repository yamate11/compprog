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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(2*N, A) [6pIpqXNh]
    auto A = vector(2*N, ll());
    for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [6pIpqXNh]
    sort(ALL(A));
    vector<pll> P(N);
    REP(i, 0, N) {
      P[i] = pll(A[i], A[N + i]);
    }
    cout << P[N - 1].first - P[0].first + P[N - 1].second - P[0].second << "\n";
    REP(i, 0, N) {
      cout << P[i].first << " " << P[i].second << "\n";
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

