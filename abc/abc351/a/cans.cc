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

  // @InpVec(9, A) [sji3iUVh]
  auto A = vector(9, ll());
  for (int i = 0; i < 9; i++) { ll v; cin >> v; A[i] = v; }
  // @End [sji3iUVh]
  // @InpVec(8, B) [fHtOQnl9]
  auto B = vector(8, ll());
  for (int i = 0; i < 8; i++) { ll v; cin >> v; B[i] = v; }
  // @End [fHtOQnl9]
  ll a = accumulate(ALL(A), 0LL);
  ll b = accumulate(ALL(B), 0LL);
  cout << a - b + 1 << endl;

  return 0;
}

