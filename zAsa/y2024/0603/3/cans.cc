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

  ll a, b, x; cin >> a >> b >> x;
  ll lim = 1e9;
  if (a * lim + b * 10 <= x) {
    cout << lim << endl;
    return 0;
  }
  ll lo = lim;
  REPrev(d, 9, 1) {
    ll hi = lo - 1;
    lo = lo / 10;
    ll rem = x - b * d;
    if (rem <= 0) continue;
    ll y = rem / a;
    if (y >= hi) {
      cout << hi << endl;
      return 0;
    }else if (y >= lo) {
      cout << y << endl;
      return 0;
    }
  }
  cout << 0 << endl;

  return 0;
}

