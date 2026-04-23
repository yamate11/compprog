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

  auto solve = [&]() -> void {
    ll N, X, Y; cin >> N >> X >> Y;
    // @InpVec(N, P, dec=1) [ithvbSgU]
    auto P = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
    // @End [ithvbSgU]
    ll j0 = min_element(P.begin() + X, P.begin() + Y) - P.begin();
    vector<ll> A, B;
    REP(i, 0, X) A.push_back(P[i]);
    REP(i, Y, N) A.push_back(P[i]);
    REP(i, j0, Y) B.push_back(P[i]);
    REP(i, X, j0) B.push_back(P[i]);
    vector<ll> ans;
    ll i0 = ssize(A);
    REP(i, 0, ssize(A)) {
      if (A[i] > B[0]) {
        i0 = i;
        break;
      }
      ans.push_back(A[i]);
    }
    REP(j, 0, ssize(B)) ans.push_back(B[j]);
    REP(i, i0, ssize(A)) ans.push_back(A[i]);
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

