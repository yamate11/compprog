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

  ll N, Q; cin >> N >> Q;
  ll ans = 0;
  vector<bool> P(N + 2, false);
  REP(i, 0, Q) {
    ll a; cin >> a;
    if (P[a] == false) {
      if (P[a - 1] and P[a + 1]) ans--;
      else if (not P[a - 1] and not P[a + 1]) ans++;
    }else {
      if (P[a - 1] and P[a + 1]) ans++;
      else if (not P[a - 1] and not P[a + 1]) ans--;
    }
    cout << ans << endl;
    P[a] = not P[a];
  }

  return 0;
}

