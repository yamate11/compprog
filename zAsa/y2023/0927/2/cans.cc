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

  // @InpVec(6, E) [9zIRlkMS]
  auto E = vector(6, ll());
  for (int i = 0; i < 6; i++) { ll v; cin >> v; E[i] = v; }
  // @End [9zIRlkMS]
  ll B; cin >> B;
  // @InpVec(6, L) [SyrK6DrA]
  auto L = vector(6, ll());
  for (int i = 0; i < 6; i++) { ll v; cin >> v; L[i] = v; }
  // @End [SyrK6DrA]

  auto vec = vector(10, 0LL);
  REP(i, 0, 6) vec[E[i]] = 1;
  vec[B] = 2;
  ll cnt = 0;
  ll bon = 0;
  REP(i, 0, 6) {
    if (vec[L[i]] == 1) cnt++;
    else if (vec[L[i]] == 2) bon = 1;
  }
  ll ans = 0;
  if (cnt == 6) ans = 1;
  else if (cnt == 5 and bon == 1) ans = 2;
  else if (cnt == 5) ans = 3;
  else if (cnt == 4) ans = 4;
  else if (cnt == 3) ans = 5;
  cout << ans << endl;

  return 0;
}

