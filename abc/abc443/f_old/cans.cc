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

  ll N; cin >> N;
  if (N < 10) {
    cout << N << endl;
    return 0;
  }
  auto enc = [&](ll p, ll k) -> ll { return p * 10 + k; };
  auto dec = [&](ll e) -> pll { return pll(e / 10, e % 10); };

  pll big(N + 1, 0);
  vector vec((N + 1) * 10, -1LL);
  vec[enc(0, 0)] = enc(0, 0);
  auto f = [&]() -> int {
    queue<ll> updated;
    REP(i, 1, 10) {
      vec[enc(i, i)] = enc(0, 0);
      updated.push(enc(i, i));
    }
    while (not updated.empty()) {
      ll e = updated.front(); updated.pop();
      auto [p, last] = dec(e);
      REP(k, last, 10) {
        ll q = (10 * p + k) % N;
        if (q == 0) q = N;
        if (vec[enc(q, k)] < 0) {
          vec[enc(q, k)] = e;
          if (q == N) return k;
          updated.push(enc(q, k));
        }
      }
    }
    return -1;
  };
  ll k0 = f();
  if (k0 < 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> ans;
  ll p = N, k = k0;
  while (p > 0) {
    ans.push_back(k);
    auto [pp, kk] = dec(vec[enc(p, k)]);
    p = pp;
    k = kk;
  }
  ranges::reverse(ans);
  REPOUT(i, 0, ssize(ans), ans[i], "");

  return 0;
}

