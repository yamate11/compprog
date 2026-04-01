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

  ll C; cin >> C;
  vector vec(C, vector<ll>(3));
  vector W(3, 0LL);
  REP(i, 0, C) {
    REP(j, 0, 3) cin >> vec[i][j];
    ranges::sort(vec[i]);
    REP(j, 0, 3) W[j] = max(W[j], vec[i][j]);
  }
  ll ans = W[0] * W[1] * W[2];
  cout << ans << endl;

  return 0;
}

