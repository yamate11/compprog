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

  ll S; cin >> S;
  ll big = 1e18;
  ll half = 1e9;

  auto out = [&](ll a, ll b, ll c, ll d, ll e, ll f) -> void {
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << "\n";
  };

  if (S == big) {
    out(0, 0, half, 0, 0, half);
  }else {
    ll p = S / half;
    ll q = S % half;
    out(0, 0, half, half - q, 1, p + 1);
  }

  return 0;
}

