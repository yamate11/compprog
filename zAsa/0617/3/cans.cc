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

  ll N; cin >> N;
  map<ll, ll> mp;
  mp[0] = 1;
  auto f = [&](auto rF, ll n) -> ll {
    auto it = mp.find(n);
    if (it != mp.end()) return it->second;
    ll ret = rF(rF, n / 2) + rF(rF, n / 3);
    mp[n] = ret;
    return ret;
  };
  cout << f(f, N) << endl;

  return 0;
}
