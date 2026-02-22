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

  ll N, K; cin >> N >> K;
  // @InpVec(N, H) [vYZAiVw6]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [vYZAiVw6]

  deque<pll> A;
  deque<pll> B;
  ll ans = 0;
  REP(i, 0, N) {
    auto f = [&](auto& V, ll h) -> ll {
      if (not V.empty()) {
        auto [x, j] = V.front();
        if (j == i - K) V.pop_front();
      }
      while (not V.empty()) {
        auto [y, k] = V.back();
        if (y > h) break;
        V.pop_back();
      }
      V.emplace_back(h, i);
      return V.front().first;
    };

    ll x = f(A, H[i]);
    ll y = f(B, -H[i]);
    ans = max(ans, x - (-y));
  }
  cout << ans << endl;
  return 0;
}

