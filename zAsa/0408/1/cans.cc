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

  ll N, M, T; cin >> N >> M >> T;
  // @InpVec(N - 1, A) [t7IkM7lb]
  auto A = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [t7IkM7lb]
  // @InpMVec(M, ((X, dec=1), Y)) [xa5RFRXN]
  auto X = vector(M, ll());
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [xa5RFRXN]

  vector B(N, 0LL);
  REP(i, 0, M) B[X[i]] = Y[i];

  ll rem = T;
  REP(i, 0, N - 1) {
    rem += B[i];
    rem -= A[i];
    if (rem <= 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

