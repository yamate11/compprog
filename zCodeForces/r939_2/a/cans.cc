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
    ll K, Q; cin >> K >> Q;
    // @InpVec(K, A) [E0Jp8i6Y]
    auto A = vector(K, ll());
    for (int i = 0; i < K; i++) { ll v; cin >> v; A[i] = v; }
    // @End [E0Jp8i6Y]
    // @InpVec(Q, N) [cstwZTaP]
    auto N = vector(Q, ll());
    for (int i = 0; i < Q; i++) { ll v; cin >> v; N[i] = v; }
    // @End [cstwZTaP]
    vector<ll> ans;
    REP(i, 0, Q) {
      if (N[i] < A[0]) ans.push_back(N[i]);
      else ans.push_back(A[0] - 1);
    }
    REPOUT(i, 0, Q, ans[i], " ");

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

