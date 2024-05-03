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

  ll N, A, X, Y; cin >> N >> A >> X >> Y;
  map<ll, double> mp;
  mp[0] = 0.0;
  auto f = [&](auto rF, ll n) -> double {
    auto it = mp.find(n);
    if (it != mp.end()) { return it->second; }
    double a = X + rF(rF, n / A);
    double z = 0.0;
    REP(i, 2, 7) z += rF(rF, n / i);
    double b = (6.0 * Y + z) / 5.0;
    double ans = min(a, b);
    mp[n] = ans;
    return ans;
  };
  cout << f(f, N) << endl;

  return 0;
}

