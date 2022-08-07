#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e18;

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    vector<ll> X(N), P(N);
    REP(i, N) cin >> X[i] >> P[i];
    map<ll, ll> mp;
    REP(i, N) {
      mp[X[i]] -= 2;
      mp[X[i] - P[i]] += 1;
      mp[X[i] + P[i]] += 1;
    }
    ll curV = 0;
    ll curT = 0;
    ll prevX = -big;
    ll dP = -big;
    ll dN = -big;
    for (auto [x, t] : mp) {
      if (prevX > -big) {
        curV += curT * (x - prevX);
        if (curV > M) {
          ll h = curV - M;
          if (dP == -big) {
            dP = h - x;
            dN = h + x;
          }else {
            dP = max(dP, h - x);
            dN = max(dN, h + x);
          }
        }
      }
      prevX = x;
      curT += t;
    }
    string ans;
    REP(i, N) {
      if (P[i] >= X[i] + dP and P[i] >= -X[i] + dN) ans += '1';
      else ans += '0';
    }
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

