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

  ll N, K, L, R; cin >> N >> K >> L >> R;
  vector vec(N, 0LL);
  REP(i, 0, N) {
    ll t; cin >> t;
    ll x;
    if (t < L) x = L - t;
    else if (t < R) x = 0;
    else x = t - R;
    vec[i] = x;
  }
  ranges::sort(vec);
  ll ans = 0;
  REP(i, 0, K) ans += vec[i];
  cout << ans << endl;

  return 0;
}

