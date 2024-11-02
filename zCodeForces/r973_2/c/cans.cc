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

  auto ask = [&](string s) -> bool {
    cout << "? " << s << endl;
    int x; cin >> x;
    if (x == 0) return false;
    else return true;
  };

  auto fin = [&](string s) -> void {
    cout << "! " << s << endl;
    return;
  };

  auto solve = [&]() -> void {
    ll N; cin >> N;
    if (not ask("0")) {
      fin(string(N, '1'));
      return;
    }
    string s = "0";
    while (true) {
      if (ssize(s) == N) {
        fin(s);
        return;
      }
      s += '0';
      if (ask(s)) {
        // do nothing
      }else {
        s[ssize(s) - 1] = '1';
        if (ask(s)) {
          // do nothing
        }else {
          s.pop_back();
          break;
        }
      }
    }
    while (ssize(s) < N) {
      string t = "0" + s;
      if (ask(t)) {
        s = t;
      }else {
        s = "1" + s;
      }
    }
    fin(s);
    return;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

