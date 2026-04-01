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
    // @InpVec(2*N, A, dec=1) [Dqj0hJ6m]
    auto A = vector(2*N, ll());
    for (int i = 0; i < 2*N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [Dqj0hJ6m]

    vector app(2, vector(N, false));
    ll cl = 0;
    vector<ll> ans;
    REP(i, 0, 2*N) {
      if (app[cl][A[i]]) {
        ans.push_back(i);
        cl = 1 - cl;
      }
      app[cl][A[i]] = true;
    }
    cout << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i], " ");

  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

