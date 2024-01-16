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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L; cin >> L;

  // binom((L - 12) + 11, 11)
  // = binom(L - 1, 11)

  auto binom = [&](ll n, ll r) -> ll {
    auto f = [&](ll a, ll b, ll c, ll d) -> pll {
      ll g = gcd(b, c);
      a *= c / g;
      b /= g;
      ll h = gcd(a, d);
      a /= h;
      b *= d / h;
      return {a, b};
    };
    ll p = 1, q = 1;
    REP(k, 0, r) tie(p, q) = f(p, q, n - k, r - k);
    assert(q == 1);
    return p;
  };

  cout << binom(L - 1, 11) << endl;

  return 0;
}

