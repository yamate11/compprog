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

  ll N, L, R; cin >> N >> L >> R;
  ll vmax = -1;
  ll i0 = -1;
  REP(i, 0, N) {
    ll p; cin >> p;
    if (L <= p and p <= R and vmax < p) {
      i0 = i;
      vmax = p;
    }
  }
  if (i0 < 0) cout << -1 << endl;
  else cout << i0 + 1 << endl;

  return 0;
}

