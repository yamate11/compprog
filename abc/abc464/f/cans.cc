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

  ll N, X; cin >> N >> X;
  // @InpVec(N, A) [fhQ4tgUa]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fhQ4tgUa]

  if (N == 1) {
    cout << A[0] << "\n";
    return 0;
  }

  ll H1 = N / 2;
  ll H2 = N - H1;
  ll sz1 = 1LL << H1;
  REP(x, 0, sz1) {
    ll v = 0;
    REP(i, 0, H1) if (x >> i & 1) v += A[i];
    B.emplace_back(v, x);
  }
  ranges::sort(B, greater<pll>());
  vector C(sz1 + 1, vector(H1, 0LL));
  REP(i, 0, sz1) {
    REP(j, 0, N) C[i + 1][j] = C[i][j] + ((B[i].second >> i & 1) ? 0 : 1);
  }
  ll sz2 = 1LL << H2;
  REP(y, 0, sz2) {
    ll w = 0;
    REP(i, 0, H2) if (y >> i & 1) w += A[H1 + i];
    ll k = ranges::lower_bound(B, pll(X - w, -1LL)) - B.begin();
    REP(i, 0, H2) if (not (y >> i & 1)) D[k][H1 + i]
  }

  return 0;
}

