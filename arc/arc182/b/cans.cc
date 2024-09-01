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
    ll N, K; cin >> N >> K;
    if (N >= (1LL << K) - 1) {
      vector<ll> ans(N, 0);
      REP(i, 0, N) ans[i] = min(i + 1, (1LL << K) - 1);
      REPOUT(i, 0, N, ans[i], " ");
    }else {
      vector<ll> ans(N, 0LL);
      REP(i, 0, N) if (i < (1LL << (K - 1))) ans[i] |= (1LL << (K - 1));
      ll turn = 1;
      REPrev(k, K - 2, 0) {
        ll v = 1;
        ll idx = -1;
        while (idx < N) {
          REP(i, 0, turn) {
            idx++;
            if (idx == N) break;
            ans[idx] |= (v << k);
          }
          v = 1 - v;
        }
        turn *= 2;
      }
      REPOUT(i, 0, N, ans[i], " ");
    }
  };

  ll T; cin >> T;
  REP(i, 0, T) solve();
  


  return 0;
}

