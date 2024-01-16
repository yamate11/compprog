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

  auto func = [&](ll x) -> ll {
    if (x <= 9) return 0;
    string s = to_string(x);
    ll sz = SIZE(s);
    if (s[0] >= '2') {
      s[0] = '1';
      REP(i, 1, sz) s[i] = '0';
      return stoll(s) - 1;
    }
    assert(s[0] == '1');
    ll i = 0;
    while (i < sz and s[i] == '1') i++;
    if (i == sz) {
      s.pop_back();
      return stoll(s);
    }
    if (s[i] == '0') {
      s.pop_back();
      return stoll(s);
    }else {
      return stoll(s.substr(1, sz - 1));
    }
  };

  auto solve = [&]() -> void {
    ll L, R; cin >> L >> R;
    cout << R - max(func(R), (L - 1)) << endl;
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

