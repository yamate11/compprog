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

  ll aa, bb, x, y; cin >> aa >> bb >> x >> y;
  
  auto f = [&](auto rF, ll a, ll b) -> ll {
    if (a == b or b + 1 == a) return x;
    if (a < b) return rF(rF, a + 1, b) + min(2 * x, y);
    else return rF(rF, a - 1, b) + min(2 * x, y);
  };
  cout << f(f, aa, bb) << endl;


  return 0;
}

