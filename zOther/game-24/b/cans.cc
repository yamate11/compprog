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

  ll H, W, N; cin >> H >> W >> N;
  ll rmax = -1;
  ll rmin = H;
  ll cmax = -1;
  ll cmin = W;
  REP(i, 0, N) {
    ll r, c; cin >> r >> c; r--; c--;
    rmax = max(rmax, r);
    rmin = min(rmin, r);
    cmax = max(cmax, c);
    cmin = min(cmin, c);
  }
  ll a = rmin ^ cmin ^ (H - 1 - rmax) ^ (W - 1 - cmax);
  cout << (a == 0 ? "Bob\n" : "Alice\n");

  return 0;
}

