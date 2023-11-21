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

  ll N, X; cin >> N >> X;
  vector tbl_init(X + 1, false);
  auto tbl = tbl_init;
  tbl[0] = true;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll a, b; cin >> a >> b;
    REPrev(j, X, 0) {
      if (prev[j]) {
        if (j + a <= X) tbl[j + a] = true;
        if (j + b <= X) tbl[j + b] = true;
      }
    }
  }
  cout << (tbl[X] ? "Yes\n" : "No\n");

  return 0;
}

