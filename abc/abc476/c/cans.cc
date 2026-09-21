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

int main() {
  ll N; cin >> N;
  ll a = 0, b = 0, c = 0;
  REP(i, 0, N) {
    ll x; cin >> x;
    if (x > a) swap(x, a);
    if (x > b) swap(x, b);
    if (x > c) swap(x, c);
    if (i >= 2) cout << c << "\n";
  }
  return 0;
}

