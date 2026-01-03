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

  ll N; cin >> N;
  ll x = 1;
  ll n = 0;
  while (true) {
    auto check = [&]() -> bool {
      ll y = x;
      ll r = y % 10;
      y /= 10;
      while (y > 0) {
        if (y % 10 != r) return false;
        y /= 10;
      }
      return true;
    };
    if (check()) {
      n++;
      if (n == N) {
        cout << x << endl;
        return 0;
      }
    }
    x++;
  }

  return 0;
}

