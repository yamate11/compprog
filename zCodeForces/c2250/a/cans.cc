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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    // @InpVec(N, W) [ks7q5yun]
    auto W = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
    // @End [ks7q5yun]
    if (N % 2 != 0) return false;
    ll a0 = 1e10;
    ll a1 = -1;
    REP(i, 0, N) {
      if (i % 2 == 0) a0 = min(a0, W[i]);
      else a1 = max(a1, W[i]);
    }
    if (a0 - a1 >= 2) return true;
    else return false;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

