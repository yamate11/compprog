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
    ll N; cin >> N;
    // @InpVec(N, A) [c3VIS7iK]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [c3VIS7iK]
    vector<ll> B1, B2, B3, B6;
    for (ll a : A) {
      if (a % 6 == 0) B6.push_back(a);
      else if (a % 3 == 0) B3.push_back(a);
      else if (a % 2 == 0) B2.push_back(a);
      else B1.push_back(a);
    }
    vector<ll> ans;
    for (ll a : B6) ans.push_back(a);
    for (ll a : B3) ans.push_back(a);
    for (ll a : B1) ans.push_back(a);
    for (ll a : B2) ans.push_back(a);
    REPOUT(i, 0, N, ans[i], " ");


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

