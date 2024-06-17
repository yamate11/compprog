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

  vector<ll> v(19);
  v[0] = 1;
  v[1] = 9;
  REP(i, 2, 19) v[i] = v[i - 1] * 9;

  auto solve = [&]() -> ll {
    ll K; cin >> K; K--;
    ll k = 1;
    while (K >= v[k]) {
      K -= v[k];
      k++;
    }
    ll ans = 0;
    ll prev = 0;
    REPrev(i, k, 1) {
      ll y = K / v[i - 1];
      ll z = K % v[i - 1];
      if (y >= prev) y++;
      ans = 10 * ans + y;
      prev = y;
      K = z;
    }
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";
  

  return 0;
}

