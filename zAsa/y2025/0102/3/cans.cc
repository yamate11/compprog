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
  // @InpVec(M, X) [a1Jq5BD7]
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; X[i] = v; }
  // @End [a1Jq5BD7]
  sort(ALL(X));
  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> gap(M - 1);
  REP(i, 0, M - 1) gap[i] = X[i + 1] - X[i];
  sort(ALL(gap), greater<ll>());
  ll s = 0;
  REP(i, 0, N - 1) s += gap[i];
  cout << X[M - 1] - X[0] - s << endl;
  

  return 0;
}

