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

  unordered_map<ll, ll> mp;
  auto f = [&](auto rF, ll x) -> ll {
    if (mp.contains(x)) return mp[x];
    ll ret;
    if (x == 1) ret = 0;
    else {
      ll y = x / 2;
      ll z = x - y;
      ret = x + rF(rF, y) + rF(rF, z);
    }
    mp[x] = ret;
    return ret;
  };
  ll N; cin >> N;
  cout << f(f, N) << endl;

  return 0;
}

