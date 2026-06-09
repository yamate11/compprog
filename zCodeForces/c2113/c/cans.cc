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
    ll n, m, k; cin >> n >> m >> k;
    vector<string> A(n);
    REP(i, 0, n) cin >> A[i];
    vector B(n, vector(m + 1, 0LL));
    REP(i, 0, n) {
      REP(j, 0, m) B[i][j + 1] = B[i][j] + (A[i][j] == 'g' ? 1 : 0);
    }
    ll tot = 0;
    REP(i, 0, n) REP(j, 0, m) if (A[i][j] == 'g') tot++;
    
    ll big = 1e18;
    ll lost = big;
    REP(j, 0, m) {
      ll b = min(m, j + k - 1 + 1);
      ll a = max(0LL, j - (k - 1));
      ll x = 0;
      REP(i, 0, n) {
        if (i == 0) {
          x = 0;
          ll e = min(k - 1 + 1, n);
          REP(ii, 0, e) x += B[ii][b] - B[ii][a];
        }else {
          ll d = i + k - 1;
          if (d <= n - 1) x += B[d][b] - B[d][a];
          ll c = i - (k - 1) - 1;
          if (c >= 0) x -= B[c][b] - B[c][a];
        }
        if (A[i][j] == '.') lost = min(lost, x);
      }
    }
    cout << tot - lost << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

