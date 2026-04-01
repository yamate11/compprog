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
  ll cnt = 0;
  vector<pll> vec;
  REP(i, 0, N) {
    ll a; cin >> a;
    if (vec.empty()) {
      vec.emplace_back(a, 1);
      cnt = 1;
    }else {
      auto [x, n] = vec.back(); vec.pop_back();
      if (x != a) {
        vec.emplace_back(x, n);
        vec.emplace_back(a, 1);
        cnt++;
      }else {
        n++;
        cnt++;
        assert(n <= a);
        if (n < a) {
          vec.emplace_back(x, n);
        }else {
          cnt -= a;
        }
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}

