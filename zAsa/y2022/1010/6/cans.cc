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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K = 7;
  vector<ll> pow3(K + 1);
  pow3[0] = 1; REP(i, 0, K) pow3[i + 1] = pow3[i] * 3;
  cout << pow3[K] << "\n";
  auto f = [&](auto rF, ll k, ll x, ll y) -> void {
    if (k == 0) {
      cout << x << " " << y << "\n";
    }else {
      ll p = pow3[k - 1];
      rF(rF, k - 1, x, y);
      rF(rF, k - 1, x, y + p);
      rF(rF, k - 1, x + p, y + p);
    }
  };
  f(f, K, 0, 0);
  return 0;
}

