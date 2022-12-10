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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  vector<ll> v{0};
  auto nxt = [&](auto rF, ll i) -> void {
    if (i == SIZE(v) - 1) {
      if (v[i] == 9) {
        v[i] = 0;
        v.push_back(1);
        return;
      }else {
        v[i]++;
        return;
      }
    }
    if (v[i] <= v[i + 1] and v[i] + 1 <= 9) {
      v[i]++;
      return;
    }
    rF(rF, i + 1);
    if (v[i + 1] == 0) {
      v[i] = 0;
      return;
    }
    v[i] = v[i + 1] - 1;
    return;
  };

  REP(k, 0, K) {
    nxt(nxt, 0);
#if DEBUG
    // REPOUT(i, 0, SIZE(v), v[i], "");
#endif
  }
  reverse(ALL(v));
  REPOUT(i, 0, SIZE(v), v[i], "");

  return 0;
}

