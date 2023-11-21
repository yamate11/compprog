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
  // @InpVec(N, T) [U5B8FmEB]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [U5B8FmEB]

  ll tot = 0;
  REP(i, 0, N) tot += T[i];

  ll lim = 1e5;
  vector<ll> tbl(lim + 1, false);
  tbl[0] = true;
  REP(i, 0, N) {
    REPrev(j, lim, 0) {
      if (j + T[i] <= lim and tbl[j]) tbl[j + T[i]] = true;
    }
  }
  
  ll ans = lim;
  REP(i, 0, lim) if (tbl[i]) ans = min(ans, max(i, tot - i));
  cout << ans << endl;

  return 0;
}

