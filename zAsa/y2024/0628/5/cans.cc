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

  string S; cin >> S;
  reverse(ALL(S));
  ll len = ssize(S);
  
  auto tbl = vector(len + 1, vector(2, -1LL));
  auto f = [&](auto rF, ll d, ll carry) -> ll {
    ll& r = tbl[d][carry];
    if (r < 0) {
      if (d == len) {
        r = carry;
      }else {
        ll x = S[d] - '0' + carry;
        ll opt1 = x + rF(rF, d + 1, 0);
        ll opt2 = (10 - x) + rF(rF, d + 1, 1);
        r = min(opt1, opt2);
      }
    }
    return r;
  };

  cout << f(f, 0, 0) << endl;

  return 0;
}

