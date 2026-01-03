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

  // @InpMVec(3, (X, Y)) [iViJ3ok3]
  auto X = vector(3, ll());
  auto Y = vector(3, ll());
  for (int i = 0; i < 3; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [iViJ3ok3]

  auto f = [&](ll a, ll b, ll c) -> ll {
    if (a == b) return c;
    if (a == c) return b;
    if (b == c) return a;
    assert(0);
  };

  ll x = f(X[0], X[1], X[2]);
  ll y = f(Y[0], Y[1], Y[2]);
  cout << x << " " << y << endl;

  return 0;
}

