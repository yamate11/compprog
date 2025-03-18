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
    // @InpVec(N, P, dec=1) [gmte2bdH]
    auto P = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
    // @End [gmte2bdH]
    vector revP(N, 0LL);
    REP(i, 0, N) revP[P[i]] = i;

    vector<ll> ans;
    ll parity = 0;
    auto op = [&](ll idx) -> void {
      assert(idx % 2 == parity);
      ans.push_back(idx);
      revP[P[idx + 1]] = idx;
      revP[P[idx]] = idx + 1;
      swap(P[idx], P[idx + 1]);
      parity = 1 - parity;
    };

    auto f = [&](auto rF, ll n) -> void {
      if (n == 2) {
        if (P[0] == 1) {
          assert(parity == 0);
          op(0);
        }
        return;
      }
      if (n == 3) {
        while (P[0] != 0 or P[1] != 1 or P[2] != 2) {
          if (parity == 0) op(0);
          else op(1);
        }
        return;
      }
      if (P[n - 1] != n - 1) {
        if (n == 4) {
          if (P[2] == 3 and parity == 1) {
            op(1);
          }
        }
        ll idx = revP[n - 1];
        if (idx % 2 != parity) {
          ll left = parity == 0 ? 0 : 1;
          if (left + 1 < idx) {
            op(left);
          }else {
            if (idx + 1 + 1 < n) {
              op(idx + 1);
            }else {
              assert(0);
            }
          }
          idx = revP[n - 1];
        }
        assert(idx % 2 == parity);
        while (revP[n - 1] < n - 1) op(revP[n - 1]);
      }
      rF(rF, n - 1);
    };
    
    f(f, N);
    cout << ssize(ans) << "\n";
    REPOUT(i, 0, ssize(ans), ans[i] + 1, " ");

  };

  ll T; cin >> T;
  REP(t, 0, T) solve();
  
  return 0;
}

