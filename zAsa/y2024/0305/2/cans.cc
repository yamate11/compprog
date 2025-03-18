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

  auto func = [](ll y, ll m, ll d) -> ll {
    if (m <= 2) {
      y--;
      m += 12;
    }
    return 365 * y + (y / 4) - (y / 100) + (y / 400) + (306 * (m + 1) / 10) + d - 429;
  };
  ll y, m, d; cin >> y >> m >> d;
  cout << func(2014, 5, 17) - func(y, m, d) << endl;

  return 0;
}

