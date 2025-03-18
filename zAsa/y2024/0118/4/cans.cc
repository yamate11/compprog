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

  ll K, T; cin >> K >> T;
  // @InpVec(T, A) [kJQbTAVZ]
  auto A = vector(T, ll());
  for (int i = 0; i < T; i++) { ll v; cin >> v; A[i] = v; }
  // @End [kJQbTAVZ]

  ll m0 = *max_element(ALL(A));
  ll ans = 0;
  if (K % 2 == 0) {
    ll half = K / 2;
    if (m0 <= half) ans = 0;
    else if (m0 == half + 1) ans = 1;
    else ans = 1 + 2 * (m0 - half - 1);
  }else {
    ll halfp = (K + 1) / 2;
    if (m0 <= halfp) ans = 0;
    else ans = 2 * (m0 - halfp);
  }
  cout << ans << endl;
  return 0;
}

