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
  using sta = pair<ll, string>;
  vector<sta> PS;
  ll t = 0;
  REP(i, N) {
    string s; cin >> s;
    ll p; cin >> p;
    PS.emplace_back(p, s);
    t += p;
  }
  sort(ALL(PS), greater<sta>());
  auto [x, y] = PS[0];
  if (x * 2 > t) cout << y << endl;
  else  cout << "atcoder\n";

  return 0;
}

