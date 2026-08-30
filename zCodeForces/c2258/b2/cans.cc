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
    ll N, M; cin >> N >> M;
    // @InpVec(N, A) [GgMGMWY5]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [GgMGMWY5]
    vector<ll> cnt(M + 1);
    ll tot = 0;
    REP(i, 0, N) {
      cnt[A[i]]++;
      tot += A[i];
    }
    ll amax = *ranges::max_element(A);

    vector<ll> ans(M + 1);
    REP(k, 1, M + 1) {
      if ((1LL << k) >= amax) ans[k] = tot;
      else {
        ll val = 0;
        for (ll goal = 1; goal <= amax; goal *= 2) {
          ll cur = 0;
          REP(a, 1, M + 1) {
            ll b = a / goal;
            if (b <= (1LL << k)) cur += cnt[a] * b;
            else cur += cnt[a] * ((1LL << k) - 1);
          }
          val = max(val, cur);
        }
        ans[k] = val;
      }
    }


    
    REPOUT(k, 1, M + 1, ans[k], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

