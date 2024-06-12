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
  vector pow3(10, 0LL);
  pow3[0] = 1;
  REP(i, 1, 10) pow3[i] = 3 * pow3[i - 1];
  ll m = pow3[N];
  vector<string> ans(m, string(m, '.'));

  auto f = [&](auto rF, ll i0, ll j0, ll k) -> void {
    if (k == 0) {
      ans[i0][j0] = '#';
      return;
    }
    REP(i, 0, 3) REP(j, 0, 3) {
      if (i == 1 and j == 1) continue;
      rF(rF, i0 + i * pow3[k - 1], j0 + j * pow3[k - 1], k - 1);
    }
  };

  f(f, 0, 0, N);
  REP(i, 0, m) {
    cout << ans[i] << "\n";
  }

  return 0;
}

