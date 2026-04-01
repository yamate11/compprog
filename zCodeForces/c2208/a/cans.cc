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
    vector cnt(N * N, 0LL);
    // @InpGrid(N, N, A, dec=1) [O6EHf2Gx]
    auto A = vector(N, vector(N, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; v -= 1; A[i][j] = v; }
    // @End [O6EHf2Gx]
    if (N == 1) {
      cout << "NO\n";
      return;
    }
    REP(i, 0, N) REP(j, 0, N) cnt[A[i][j]]++;
    ll x = *ranges::max_element(cnt);
    if (x <= N * N - N) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

