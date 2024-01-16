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

  ll N, C; cin >> N >> C;
  // @InpVec(N, A) [mrzO1YgA]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mrzO1YgA]

  auto f = [&](ll r) -> tuple<ll, ll, ll, ll> {
    vector<ll> cnt(11);
    ll tot = 0;
    REP(i, 0, N) {
      if (i % 2 == r) {
        cnt[A[i]]++;
        tot++;
      }
    }
    vector<ll> ord(11);
    REP(i, 0, 11) ord[i] = i;
    sort(ALL(ord), [&](ll i, ll j) -> bool { return cnt[i] > cnt[j]; });
    return {tot - cnt[ord[0]], ord[0], tot - cnt[ord[1]], ord[1]};
  };

  auto [p0, cp0, p1, cp1] = f(0);
  auto [q0, cq0, q1, cq1] = f(1);
  ll ans;
  if (cp0 == cq0) ans = min(p0 + q1, q0 + p1);
  else ans = p0 + q0;
  cout << ans * C << endl;

  return 0;
}

