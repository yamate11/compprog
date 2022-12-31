#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [&](auto& A, auto& B, ll K) {
    vector<ll> ret;
    for (ll b : B) ret.push_back(A[0] + b);
    REP2(i, 1, SIZE(A)) {
      ll lim = K - 1 < SIZE(ret) ? ret[K - 1] : 0;
      for (ll b : B) {
        if (A[i] + b < lim) break;
        ret.push_back(A[i] + b);
      }
      sort(ALL(ret), greater<ll>());
      if (SIZE(ret) > K) ret.resize(K);
    }
    return ret;
  };

  ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
  vector <ll> A(X), B(Y), C(Z);
  REP(i, X) cin >> A[i];
  REP(i, Y) cin >> B[i];
  REP(i, Z) cin >> C[i];
  sort(ALL(A), greater<ll>());
  sort(ALL(B), greater<ll>());
  sort(ALL(C), greater<ll>());
  auto vec = f(A, B, min(X*Y, K));
  auto ans = f(vec, C, K);
  REP(i, K) cout << ans[i] << "\n";

  return 0;
}

