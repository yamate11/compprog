#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<bool> use(10, true);
  REP(i, K) {
    ll d; cin >> d;
    use[d] = false;
  }
  auto check = [&](ll x) -> bool {
    while (x > 0) {
      ll y = x % 10;
      if (not (use[y])) return false;
      x /= 10;
    }
    return true;
  };
  REP2(i, N, 1000000) {
    if (check(i)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

