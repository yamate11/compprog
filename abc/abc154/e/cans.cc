#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll sz = s.size();
  ll K; cin >> K;
  
  auto tbl = vector(K + 1, vector(2, 0LL));
  tbl[0][1] = 1;
  for (ll i = 0; i < sz; i++) {
    ll d = s[i] - '0';
    auto prev = move(tbl);
    tbl = vector(K + 1, vector(2, 0LL));
    for (ll k = 0; k <= K; k++) {
      for (ll p = 0; p < 2; p++) {
        {
          for (ll x = 0; x <= d; x++) {
            ll kn = k, pn = p;
            if (x < d) pn = 0;
            if (x > 0) kn++;
            if (kn > K) continue;
            tbl[kn][pn] += prev[k][p];
          }
        }
        {
          if (k + 1 <= K) tbl[k + 1][p] += prev[k][p] * 9;
          tbl[k][p] += prev[k][p];
        }
      }
    }
  }
  cout << tbl[K][0] + tbl[K][1] << endl;

  return 0;
}

