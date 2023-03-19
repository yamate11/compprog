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

  ll N, M, P, Q, R; cin >> N >> M >> P >> Q >> R;
  // @InpMVec(R, ((X, dec=1), (Y, dec=1), Z)) [C2i8NIKd]
  auto X = vector(R, ll());
  auto Y = vector(R, ll());
  auto Z = vector(R, ll());
  for (int i = 0; i < R; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [C2i8NIKd]

  vector A(M, vector<ll>(N, 0LL));
  REP(i, 0, R) A[Y[i]][X[i]] = Z[i];

  ll ans = 0;
  REP(x, 0, 1LL << N) {
    if (__builtin_popcountll(x) != P) continue;
    vector<ll> B(M, 0LL);
    REP(i, 0, M) {
      REP(j, 0, N) if (x >> j & 1) {
        B[i] += A[i][j];
      }
    }
    sort(ALL(B), greater<ll>());
    ll s = 0;
    REP(i, 0, Q) s += B[i];
    ans = max(ans, s);
  }
  cout << ans << endl;

  return 0;
}

