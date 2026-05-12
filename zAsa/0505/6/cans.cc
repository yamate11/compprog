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

  ll T; cin >> T;
  REP(t, 0, T) {
    ll R, B; cin >> R >> B;
    if (R % 2 != 0 or (B % 2 != 0 and R == 0)) {
      cout << "No\n";
    }else {
      cout << "Yes\n";
      ll r, c;
      auto f = [&](ll n, char ch, auto g) -> void {
        REP(i, 0, n) {
          cout << ch << " " << r << " " << c << "\n";
          if (i < n - 1) g();
        }
      };
      char cR = 'R';
      char cB = 'B';
      if (B % 2 == 0) {
        r = 1; c = 1 + R / 2;
        f(R/2, cR, [&]{ c--; });
        r++;
        f(R/2, cR, [&]{ c++; });
        r++;
        f(B/2, cB, [&]{ r++; c++; });
        r--; c++;
        f(B/2, cB, [&]{ r--; c--; });
      }else {
        r = 2; c = 1 + R / 2;
        f(R/2, cR, [&]{ c--; });
        r--;
        f(R/2, cR, [&]{ c++; });
        c++;
        f(B/2 + 1, cB, [&]{ r++; c++; });
        r++; c--;
        f(B/2, cB, [&]{ r--; c--; });
      }
    }
  }

  return 0;
}

