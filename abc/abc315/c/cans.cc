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

  ll N; cin >> N;
  // @InpMVec(N, ((F, dec=1), S)) [pknuFyR0]
  auto F = vector(N, ll());
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; v1 -= 1; F[i] = v1;
    ll v2; cin >> v2; S[i] = v2;
  }
  // @End [pknuFyR0]
  vector<vector<ll>> D(N);
  REP(i, 0, N) {
    D[F[i]].push_back(S[i]);
  }
  vector<ll> V;
  REP(i, 0, N) {
    if (not D[i].empty()) {
      sort(ALL(D[i]), greater<ll>());
      V.push_back(D[i][0]);
    }
  }
  ll ans = 0;
  if (SIZE(V) >= 2) {
    sort(ALL(V), greater<ll>());
    ans = V[0] + V[1];
  }
  REP(i, 0, N) {
    if (SIZE(D[i]) >= 2) {
      ans = max(ans, D[i][0] + D[i][1] / 2);
    }
  }
  cout << ans << endl;


  return 0;
}

