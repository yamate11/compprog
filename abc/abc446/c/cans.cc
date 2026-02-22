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

  auto solve = [&]() -> ll {
    ll N, D; cin >> N >> D;
    // @InpVec(N, A) [9X9fktF4]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [9X9fktF4]
    // @InpVec(N, B) [Yh8vpkTa]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [Yh8vpkTa]

    deque<pll> deq;
    REP(i, 0, N) {
      deq.emplace_back(A[i], i);
      ll rem = B[i];
      while (rem > 0) {
        auto [a, j] = deq.front(); deq.pop_front();
        ll x = min(rem, a);
        rem -= x;
        a -= x;
        if (a > 0) deq.emplace_front(a, j);
      }
      while (not deq.empty()) {
        auto [a, j] = deq.front();
        if (j + D > i) break;
        deq.pop_front();
      }
    }
    ll ret = 0;
    while (not deq.empty()) {
      auto [a, j] = deq.front(); deq.pop_front();
      ret += a;
    }
    return ret;
  };


  ll T; cin >> T;
  REP(_t, 0, T) cout << solve() << endl;

  return 0;
}

