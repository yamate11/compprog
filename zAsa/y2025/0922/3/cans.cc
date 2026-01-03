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

  ll W, H, N; cin >> W >> H >> N;
  ll x1 = 0;
  ll x2 = W;
  ll y1 = 0;
  ll y2 = H;
  REP(i, 0, N) {
    ll x, y, a; cin >> x >> y >> a;
    if (a == 1)      x1 = max(x, x1);
    else if (a == 2) x2 = min(x, x2);
    else if (a == 3) y1 = max(y, y1);
    else if (a == 4) y2 = min(y, y2);
  }
  cout << max(0LL, x2 - x1) * max(0LL, y2 - y1) << endl;


  return 0;
}

