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
  ll lim = 1LL << N;
  using sta = pair<ll, ll>;
  vector<sta> vec;
  REP2(i, 1, lim) {
    ll c; cin >> c;
    vec.emplace_back(c, i);
  }
  sort(ALL(vec));
  ll cnt = 0;
  ll cost = 0;
  vector<ll> aux;
  for (auto [c, x] : vec) {
    ll e = x;
    for (ll b : aux) e = min(e, e^b);
    if (e) {
      aux.push_back(e);
      cost += c;
      cnt++;
      if (cnt == N) break;
    }
  }
  cout << cost << endl;

  return 0;
}

