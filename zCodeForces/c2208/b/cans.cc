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
    ll N, K, P, M; cin >> N >> K >> P >> M; P--;
    // @InpVec(N, A) [hH0KLG9g]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [hH0KLG9g]

    if (K == N) {
      return M / A[P];
    }

    queue<ll> que;
    priority_queue<ll, vector<ll>, greater<ll>> pque;
    REP(i, 0, K) {
      if (i != P) pque.push(A[i]);
    }
    REP(i, K, N) {
      que.push(A[i]);
    }
    ll ppos;
    ll ans = 0;
    bool once = false;
    if (P < K) {
      once = true;
      if (M < A[P]) return ans;
      ans++;
      M -= A[P];
      que.push(A[P]);
      ppos = N - K;
    }else {
      ll x = pque.top(); pque.pop();
      if (M < x) return ans;
      M -= x;
      que.push(x);
      ppos = P - K;
    }
    while (true) {
      ll x = que.front(); que.pop();
      if (ppos == 0) {
        if (not once) {
          once = true;
          if (M < x) return ans;
          ans++;
          M -= x;
          que.push(x);
          ppos = N - K;
        }else {
          if (M < x) return ans;
          M -= x; ans++;
          ll s = x;
          while (not que.empty()) {
            ll z = que.front(); que.pop();
            s += z;
          }
          ans += M / s;
          return ans;
        }
      }else {
        pque.push(x);
        ll y = pque.top(); pque.pop();
        if (M < y) return ans;
        M -= y;
        que.push(y);
        ppos--;
      }
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

