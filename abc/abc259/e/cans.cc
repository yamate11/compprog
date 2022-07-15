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
  map<ll, ll> emax;
  map<ll, ll> emaxnum; 
  vector<map<ll, ll>> pe(N);
  REP(i, N) {
    ll m; cin >> m;
    REP(j, m) {
      ll p, e; cin >> p >> e;
      pe[i][p] = e;
      ll oldmax = emax[p];
      if (oldmax < e) {
        emax[p] = e;
        emaxnum[p] = 1;
      }else if (oldmax == e) {
        emaxnum[p]++;
      }
    }
  }
  ll badcnt = 0;
  REP(i, N) {
    bool bad = true;
    for (auto [p, e] : pe[i]) {
      if (emax[p] == e and emaxnum[p] == 1) {
        bad = false;
        break;
      }
    }
    if (bad) badcnt++;
  }
  ll ans = 0;
  if (badcnt <= 1) ans = N;
  else ans = N - (badcnt - 1);
  cout << ans << endl;

  return 0;
}

