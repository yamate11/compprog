#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  vector<pll> A;
  REP(i, 0, N) {
    ll t, d; cin >> t >> d; t--;
    A.emplace_back(d, t);
  }
  sort(ALL(A), greater<pll>());
  ll sumd = 0;
  vector B(N, vector<ll>());
  REP(i, 0, K) {
    auto [d, t] = A[i];
    sumd += d;
    B[t].push_back(d);
  }
  vector<ll> C;
  ll x = 0;
  REP(i, 0, N) {
    ll n = SIZE(B[i]);
    if (n >= 1) x++;
    REP(j, 1, n) C.push_back(B[i][j]);
  }
  sort(ALL(C), greater<ll>());
  ll ans = sumd + x * x;
  REP(i, K, N) {
    auto [d, t] = A[i];
    if (B[t].empty()) {
      B[t].push_back(d);
      if (C.empty()) break;
      ll z = C.back(); C.pop_back();
      sumd = sumd - z + d;
      x++;
      ans = max(ans, sumd + x * x);
    }
  }
  cout << ans << endl;

  return 0;
}

