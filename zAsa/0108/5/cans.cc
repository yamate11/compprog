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

  string N; cin >> N;
  ll sz = SIZE(N);
  reverse(ALL(N));
  vector rec(2, vector(sz + 10, -1LL));
  auto f = [&](auto rF, ll b, ll i) -> ll {
    ll& ret = rec[b][i];
    if (ret < 0) {
      if (i == sz) ret = b;
      else {
        ll d = N[i] - '0' + b;
        ll x = d + rF(rF, 0, i + 1);
        ll y = (10 - d) + rF(rF, 1, i + 1);
        ret = min(x, y);
      }
    }
    return ret;
  };
  cout << f(f, 0, 0) << endl;

  return 0;
}

