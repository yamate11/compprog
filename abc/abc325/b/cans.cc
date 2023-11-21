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

  ll N; cin >> N;
  vector<ll> vec(48, 0LL);
  REP(i, 0, N) {
    ll w, x; cin >> w >> x;
    vec[x] += w;
  }
  REP(i, 0, 24) vec[24 + i] = vec[i];
  ll ans = 0;
  REP(i, 0, 24) {
    ll t = 0;
    REP(j, 9, 18) t += vec[i + j];
    ans = max(ans, t);
  }
  cout << ans << endl;

  return 0;
}

