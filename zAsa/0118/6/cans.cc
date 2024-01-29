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

  ll L; cin >> L;
  // @InpVec(L, A) [JTp2XWyZ]
  auto A = vector(L, ll());
  for (int i = 0; i < L; i++) { ll v; cin >> v; A[i] = v; }
  // @End [JTp2XWyZ]

  vector tbl_init(5, 0LL);
  auto tbl = tbl_init;
  REP(i, 0, L) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll a = A[i];
    ll tp0 = a;
    ll tp1 = a % 2 == 0 ? 1 : 0;
    ll tp2 = a == 0 ? 2 : a % 2 == 0 ? 0 : 1;
    ll z = prev[0];
    tbl[0] = tp0 + z;
    z = min(z, prev[1]);
    tbl[1] = tp2 + z;
    z = min(z, prev[2]);
    tbl[2] = tp1 + z;
    z = min(z, prev[3]);
    tbl[3] = tp2 + z;
    z = min(z, prev[4]);
    tbl[4] = tp0 + z;
  }
  cout << *min_element(ALL(tbl)) << endl;

  return 0;
}

