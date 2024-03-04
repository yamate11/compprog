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

  ll len = 7;

  ll V1, V2, V3; cin >> V1 >> V2 >> V3;
  
  auto max3 = [&](ll a, ll b, ll c) -> ll { return max(a, max(b, c)); };
  auto min3 = [&](ll a, ll b, ll c) -> ll { return min(a, min(b, c)); };

  using sta = tuple<ll, ll, ll>;
  auto func = [&](const auto& a) -> sta {
    ll gamma = 1;
    REP(i, 0, 3) {
      ll x = max3(a[0][i], a[1][i], a[2][i]);
      ll y = min3(a[0][i] + len, a[1][i] + len, a[2][i] + len);
      ll h = max(y - x, 0LL);
      gamma *= h;
    }
    ll beta = 0;
    REP(m, 0, 3) REP(n, m + 1, 3) {
      ll com2 = 1;
      REP(i, 0, 3) {
        ll x = max(a[m][i], a[n][i]);
        ll y = min(a[m][i] + len, a[n][i] + len);
        ll h = max(y - x, 0LL);
        com2 *= h;
      }
      beta += com2;
    }
    ll alpha = len * len * len * 3;
    return sta(alpha - 2 * beta + 3 * gamma, beta - 3 * gamma, gamma);
  };
  
#if 0
  vector www{vector{0, 0, 0}, vector{0, 0, 6}, vector{0, 6, 0}};
  auto xx = func(www);
  return 0;
#endif  

  vector vec(3, vector<ll>(3, 0LL));
  if (V3 > 0) {
    REP(a2, 0, len) REP(a3, a2, len) REP(b2, -len + 1, len) REP(b3, -len + 1, len) REP(c2, -len + 1, len) REP(c3, -len + 1, len) {
      vec[1] = vector<ll>{a2, b2, c2};
      vec[2] = vector<ll>{a3, b3, c3};
      const auto [a, b, c] = func(vec);
      if (a == V1 and b == V2 and c == V3) {
        cout << "Yes\n";
        REP(i, 0, 3) REP(j, 0, 3) cout << vec[i][j] << " ";
        cout << "\n";
        return 0;
      }
    }
  }else {
    REP(a2, 0, len + 1) REP(a3, -len, a2 - len + 1) REP(b2, 0, len + 1) REP(b3, 0, len + 1) REP(c2, 0, len + 1) REP(c3, 0, len + 1) {
      vec[1] = vector<ll>{a2, b2, c2};
      vec[2] = vector<ll>{a3, b3, c3};
      const auto [a, b, c] = func(vec);
      if (a == V1 and b == V2 and c == V3) {
        cout << "Yes\n";
        REP(i, 0, 3) REP(j, 0, 3) cout << vec[i][j] << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}

