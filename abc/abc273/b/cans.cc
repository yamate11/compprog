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

  vector<ll> pow10(18);
  pow10[0] = 1;
  REP(i, 0, 17) pow10[i + 1] = pow10[i] * 10;

  auto func = [&](ll x, ll k) -> ll {
    x += pow10[k] * 5;
    ll y = x / pow10[k + 1];
    ll z = y * pow10[k + 1];
    return z;
  };

  ll X, K; cin >> X >> K;
  REP(i, 0, K) {
    X = func(X, i);
  }
  cout << X << endl;

  return 0;
}

