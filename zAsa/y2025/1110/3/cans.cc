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
  ll ans = 0;
  vector<pll> vec{{-1LL, 0}};
  REP(i, 0, N) {
    ll a; cin >> a;
    auto [x, n] = vec.back();
    if (x == a) {
      vec.pop_back();
      ans -= n;
      if (n + 1 < x) {
        vec.emplace_back(x, n + 1);
        ans += n + 1;
      }
    }else {
      vec.emplace_back(a, 1);
      ans += 1;
    }
    cout << ans << "\n";
  }

  return 0;
}

