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

  auto chg = [&](string s, char c) -> string {
    REP(i, 0, SIZE(s)) if (s[i] == '?') s[i] = c;
    return s;
  };
  auto top = [&](string s) -> ll {
    REP(i, 0, SIZE(s)) if (s[i] == '?') return i;
    return -1;
  };
  auto sval = [&](string s) -> ll {
    ll ret = 0;
    REP(i, 0, SIZE(s)) ret = 2 * ret + (s[i] == '1' ? 1 : 0);
    return ret;
  };

  string S; cin >> S;
  ll N; cin >> N;
  // ll sz = SIZE(S);
  string S0 = chg(S, '0');
  if (N < sval(S0)) {
    cout << -1 << endl;
    return 0;
  }
  while (true) {
    ll i = top(S);
    if (i < 0) {
      cout << sval(S) << endl;
      return 0;
    }
    auto x = S;
    x[i] = '1';
    chg(x, '0');
    if (N < sval(x)) {
      S[i] = '0';
    }else {
      S[i] = '1';
    }
  }
  

  return 0;
}

