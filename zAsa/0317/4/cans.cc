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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ll A, B, K; cin >> A >> B >> K;
  ll lim = A + B + 1;
  vector binom(lim, vector(lim, 0LL));
  binom[1][0] = binom[1][1] = 1;
  REP(i, 1, lim - 1) REP(j, 0, i + 1) {
    binom[i + 1][j] += binom[i][j];
    binom[i + 1][j + 1] += binom[i][j];
  }
  auto f = [&](auto rF, ll a, ll b, ll k) -> string {
    if (a == 0) return string(b, 'b');
    if (b == 0) return string(a, 'a');
    ll bn = binom[a - 1 + b][b];
    if (k <= bn) return "a" + rF(rF, a - 1, b, k);
    else         return "b" + rF(rF, a, b - 1, k - bn);
  };
  cout << f(f, A, B, K) << endl;
  return 0;
}

