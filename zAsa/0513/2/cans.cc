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

  vector<ll> xl(50);
  vector<ll> xr(50);
  ll L, R; cin >> L >> R;
  // @InpVec(L, vecL) [LrCHW9X7]
  auto vecL = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; vecL[i] = v; }
  // @End [LrCHW9X7]
  // @InpVec(R, vecR) [3bH2M26Q]
  auto vecR = vector(R, ll());
  for (int i = 0; i < R; i++) { ll v; cin >> v; vecR[i] = v; }
  // @End [3bH2M26Q]
  REP(i, 0, L) xl[vecL[i]]++;
  REP(i, 0, R) xr[vecR[i]]++;
  ll ans = 0;
  REP(i, 0, 50) ans += min(xl[i], xr[i]);
  cout << ans << endl;

  return 0;
}

