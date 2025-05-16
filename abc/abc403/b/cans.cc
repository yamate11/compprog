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

  string T; cin >> T;
  string U; cin >> U;
  ll n = ssize(T);
  ll m = ssize(U);
  REP(i, 0, n + 1) {
    if (i + m > n) break;
    auto check = [&]() -> bool {
      REP(j, 0, m) {
        ll c1 = T[i + j];
        ll c2 = U[j];
        if (c1 == c2 or c1 == '?') {
          ;
        }else {
          return false;
        }
      }
      return true;
    };
    if (check()) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

