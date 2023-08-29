#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

int main() {
  vector<ll> a{1, 2, 3, 4, 5};
  map<ll, ll> mp;
  vector<vector<ll>> b{{1, 2, 3}, {4, 5}, {6, 7, 8}, {}};
  mp[3] = 5;
  mp[7] = 2;
  ll x = 0;
  REP(i, 0, 5) {
    x += i / (a[i] - 3);
  }
  return 0;
}
