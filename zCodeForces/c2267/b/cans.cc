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
    // @InpVec(N, A) [Drwl4wbJ]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [Drwl4wbJ]

    vector<ll> cnt(101);
    REP(i, 0, N) cnt[A[i]]++;
    vector<ll> ans;
    while (true) {
      auto getmax = [&]() -> ll {
        REPrev(i, 100, 1) {
          if (cnt[i] > 0) return i;
        }
        return -1;
      };
      ll n = getmax();
      if (n < 0) break;
      ll k = cnt[n];
      REP(i, 0, k) ans.push_back(n);
      cnt[n] = 0;
      REPrev(i, n - 1, 1) {
        ll m = min(cnt[i], k);
        REP(j, 0, m) ans.push_back(i);
        cnt[i] -= m;
      }
    }
    REPOUT(i, 0, ssize(ans), ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

