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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, G, type=string) [uLgmpMRi]
    auto G = vector(N, string());
    for (int i = 0; i < N; i++) { string v; cin >> v; G[i] = v; }
    // @End [uLgmpMRi]
    vector<ll> ans(N, -1LL);
    REP(i, 0, N) {
      ll s = 0;
      REP(j, i + 1, N) s += G[i][j] - '0';
      ll t = 0;
      REPrev(j, N - 1, 0) {
        if (ans[j] >= 0) continue;
        if (t == s) {
          ans[j] = i;
          break;
        }
        t++;
      }
    }
    REPOUT(i, 0, N, ans[i] + 1, " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

