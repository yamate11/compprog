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

  auto solve = [&]() -> void {
    string S; cin >> S;
    if (ssize(S) == 1) {
      cout << S << "\n";
      return;
    }
    vector<ll> cnt(10);
    for (char c : S) cnt[c - '0']++;
    ll x = 0;
    REP(i, 0, 10) x += i * cnt[i];
    REP(r, 1, 100) {
      ll y = x - r;
      assert(y > 0);
      vector<ll> vec(10);
      auto op = [&](ll z) -> ll {
        ll ret = 0;
        while (z > 0) {
          ll c = z % 10;
          vec[c]++;
          ret += c;
          z /= 10;
        }
        return ret;
      };
      vector<ll> tmp;
      ll z = y;
      while (z > 9) {
        tmp.push_back(z);
        z = op(z);
      }
      tmp.push_back(z);
      vec[z]++;
      ll t = 0;
      bool fail = false;
      REP(i, 0, 10) {
        if (cnt[i] < vec[i]) {
          fail = true;
          break;
        }
        t += i * (cnt[i] - vec[i]);
      }
      if (not fail and y == t) {
        REPrev(i, 9, 0) {
          REP(j, 0, cnt[i] - vec[i]) cout << i;
        }
        for (ll zz : tmp) cout << zz;
        cout << "\n";
        return;
      }
    }
    assert(0);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

