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

  vector pow10(17, 0LL);
  pow10[0] = 1;
  REP(i, 1, 17) pow10[i] = pow10[i - 1] * 10;

  auto f = [&](ll x, ll i) -> ll {
    return (x + pow10[i] * 5) / pow10[i + 1] * pow10[i + 1];
  };

  ll X, K; cin >> X >> K;
  REP(i, 0, K) X = f(X, i);
  cout << X << endl;

  return 0;
}

