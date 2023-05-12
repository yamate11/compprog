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
  ll A, B, C; cin >> A >> B >> C;
  
  ll a = A % 10;
  ll q = 1;
  REP(i, 0, C) q *= B;
  ll ans = 1;
  REP(i, 0, q) ans = (ans * a) % 10;
  cout << ans << endl;

  return 0;
}
