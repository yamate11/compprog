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
  // @InpVec(N, P, dec=1) [Ya7t0p5t]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [Ya7t0p5t]

  using sta = tuple<ll, ll, ll>;
  vector<sta> vec;
  REP(i, 0, N) REP(j, i + 1, N) {
    if (j - i >= K and P[i] > P[j]) vec.emplace_back(i, j, 1);
  }
  vector<pll> ans;
  ll big = 1e18;
  while (not vec.empty()) {
    ll w = big;
    ll i0;
    REP(i, 0, ssize(vec)) {
      auto [a, b, yet] = vec[i];
      if (yet and P[a] > P[b] and P[a] - P[b] < w) {
        w = P[a] - P[b];
        i0 = i;
        if (w == 1) break;
      }
    }
    auto [a, b, yet] = vec[i0];
    ans.emplace_back(a, b);
    swap(P[a], P[b]);
    if (i0 < ssize(vec) - 1) swap(vec[i0], vec[ssize(vec) - 1]);
    vec.pop_back();
  }
  cout << ssize(ans) << "\n";
  for (auto [a, b] : ans) {
    cout << a + 1 << " " << b + 1 << "\n";
  }


  return 0;
}

