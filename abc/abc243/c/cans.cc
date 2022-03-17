#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  ll N; cin >> N;
  vector<ll> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];
  string S; cin >> S;
  map<ll, pair<vector<ll>, vector<ll>>> mp;
  REP(i, N) {
    auto& p = mp[Y[i]];
    if (S[i] == 'L') p.first.push_back(X[i]);
    else             p.second.push_back(X[i]);
  }
  for (auto& [y, p] : mp) {
    if (p.first.empty() or p.second.empty()) continue;
    ll lmax = -1;
    for (ll x : p.first) lmax = max(lmax, x);
    ll rmin = 1e10;
    for (ll x : p.second) rmin = min(rmin, x);
    if (rmin < lmax) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

