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

  auto f = [&](auto rF, ll x) -> ll {
    if (x <= 9) return x + 1;
    ll p = x / 10;
    ll q = x % 10;
    ll r = p % 10;
    if (q < 9 and abs(q + 1 - r) <= 1) return x + 1;
    ll y = rF(rF, p);
    ll s = y % 10;
    ll t = max(s - 1, 0LL);
    return y * 10 + t;
  };

  ll K; cin >> K;
  ll x = 1;
  REP(i, 0, K - 1) x = f(f, x);
  cout << x << endl;

  return 0;
}

