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

  vector vec(5, 0LL);
  REP(i, 0, 5) cin >> vec[i];
  vector<pair<ll, string>> vv;
  REP(x, 1, 32) {
    string name;
    ll val = 0;
    REP(i, 0, 5) {
      if (x >> i & 1) {
        name += (char)('A' + i);
        val += vec[i];
      }
    }
    vv.emplace_back(-val, name);
  }
  sort(ALL(vv));
  for (auto [v, n] : vv) {
    cout << n << "\n";
  }
  

  return 0;
}

