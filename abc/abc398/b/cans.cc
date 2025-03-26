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

  map<ll, ll> mp;
  REP(i, 0, 7) {
    ll x; cin >> x;
    mp[x]++;
  }
  vector<pll> vec;
  for (auto [x, n] : mp) {
    vec.emplace_back(n, x);
  }
  sort(ALL(vec), greater<pll>());
  if (ssize(vec) >= 2 and vec[0].first >= 3 and vec[1].first >= 2) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }


  return 0;
}

