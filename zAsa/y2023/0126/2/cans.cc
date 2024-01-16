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

  ll L, R; cin >> L >> R;
  // @InpVec(L, l) [Nl6dFAOC]
  auto l = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; l[i] = v; }
  // @End [Nl6dFAOC]
  // @InpVec(R, r) [czXePXNE]
  auto r = vector(R, ll());
  for (int i = 0; i < R; i++) { ll v; cin >> v; r[i] = v; }
  // @End [czXePXNE]
  vector<ll> vl(41);
  vector<ll> vr(41);
  REP(i, 0, L) vl[l[i]]++;
  REP(i, 0, R) vr[r[i]]++;
  ll s = 0;
  REP(i, 10, 41) s += min(vl[i], vr[i]);
  cout << s << endl;

  return 0;
}

