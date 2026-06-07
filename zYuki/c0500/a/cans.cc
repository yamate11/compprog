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

  ll N, M; cin >> N >> M;
  ll x = 0;
  REP(k, 0, 30) {
    ll a = (N >> k) & 1;
    ll b = (M >> k) & 1;
    if (k % 2 == 0) {
      if (a == 0 and b == 1) {
        cout << -1 << endl;
        return 0;
      }
      ll z = (a == 1 and b == 1) ? 1 : 0;
      x |= z << k;
    }else {
      if (a == 1 and b == 0) {
        cout << -1 << endl;
        return 0;
      }
      ll z = (a == 0 and b == 1) ? 1 : 0;
      x |= z << k;
    }
  }
  cout << x << endl;

  return 0;
}

