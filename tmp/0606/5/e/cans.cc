#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll n = SIZE(S);
  vector tbl(2, vector(n, -1LL));
  auto func = [&](auto rF, ll f, ll k) -> ll {
    if (k == n) return f;
    ll& ret = tbl[f][k];
    if (ret < 0) {
      ll d = S[n - 1 - k] - '0';
      d = d + f;
      ll a = rF(rF, 0, k + 1) + d;
      ll b = rF(rF, 1, k + 1) + (10 - d);
      ret = min(a, b);
    }
    return ret;
  };
  cout << func(func, 0, 0) << endl;

  return 0;
}

