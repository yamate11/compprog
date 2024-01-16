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

  ll lim = 1e6;
  vector vec(lim + 2, 0LL);
  ll N; cin >> N;
  REP(i, 0, N) {
    ll a, b; cin >> a >> b;
    vec[a]++;
    vec[b + 1]--;
  }
  ll ans = 0;
  ll v = 0;
  REP(i, 0, lim + 2) {
    v += vec[i];
    ans = max(ans, v);
  }
  assert(v == 0);
  cout << ans << endl;

  return 0;
}

