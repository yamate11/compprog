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
    ll n; cin >> n;

    ll open;
    ll close;
      auto init_close = [&](ll lime) -> ll {
        vector<ll> vec(500, open);
        REP(i, 0, min(500, lim)) vec.push_back(i);
        ll x3 = ask(vec);
        if (x3 < 500) return x3;
        vector<ll> vec2(500, open);
        REP(i, 0, lim - 500) vec.push_back(500 + i);
        ll x4 = ask(vec2);
        return 500 + x4;
      };

    ll lo = 0;
    ll x = ask_seq(0, n);
    if (x == 0) {
      vector<ll> vec;
      REPrev(i, n - 1, 0) vec.push_back(i);
      ll x2 = ask(vec);
      string ans;
      REP(i, 0, n - x2) ans += ')';
      REP(i, 0, x2) ans += '(';
      report(ans);
    }else {
      ll lo = 1;
      ll hi = n;
      while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll x2 = ask_seq(0, mid);
        if (x2 == 0) lo = mid;
        else hi = mid;
      }
      open = lo - 1;
      close = hi;
      ll ic = init_close(lo - 1);
      ll io = lo - 1 - ic;
      string ans(ic, ')');
      ans += string(io, '(');
      ans += "()";
      for (ll j = hi; j < n; j += 2) {
        ll k;
        if (j + 1 == n) {
          k = j;
        }else {
          k = j + 1;
        }
        vector<ll> vec(15, close);
        vec[0] = vec[5] = vec[10] = open;
        vec[1] = j;
        vec[6] = vec[11] = k;
        ll xx = ask(vec);
        if (j + 1 == n) {
          if (xx == 6) ans += "(";
          else ans += ")";
        }else {
          if (xx == 6 or xx == 4) ans += "(";
          else ans += ")";
          if (xx == 6 or xx == 5) ans += "(";
          else ans += ")";
        }
      }
    }

    

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

