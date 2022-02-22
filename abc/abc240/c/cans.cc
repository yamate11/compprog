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

  ll N, X; cin >> N >> X;
  vector<bool> tbl_init(X + 1);
  auto tbl = tbl_init;
  tbl[0] = true;
  REP(i, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll a, b; cin >> a >> b;
    REP(j, X + 1) {
      if (not prev[j]) continue;
      if (j + a <= X) tbl[j + a] = true;
      if (j + b <= X) tbl[j + b] = true;
    }
  }
  cout << (tbl[X] ? "Yes\n" : "No\n");

  return 0;
}

