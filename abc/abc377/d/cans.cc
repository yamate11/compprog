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

  ll N, M; cin >> N >> M;
  vector vec(N, pll());
  REP(i, 0, N) {
    ll l, r; cin >> l >> r; l--;
    vec[i] = pll(l, r);
  }
  sort(ALL(vec));
  multiset<ll> rights;
  REP(i, 0, N) rights.insert(vec[i].second);
  ll ans = 0;
  ll idx = 0;
  REP(x, 0, M) {
    if (rights.empty()) {
      ans += M - x;
    }else {
      ll a = *rights.begin();
      ans += a - x - 1;
    }
    while (idx < N and vec[idx].first == x) {
      auto it = rights.find(vec[idx].second);
      assert(it != rights.end());
      rights.erase(it);
      idx++;
    }
  }
  cout << ans << endl;
  return 0;
}

