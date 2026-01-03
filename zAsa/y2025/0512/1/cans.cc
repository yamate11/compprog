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

  ll N, Q; cin >> N >> Q;
  // @InpVec(Q, T, dec=1) [lUFhsJqK]
  auto T = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; v -= 1; T[i] = v; }
  // @End [lUFhsJqK]
  vector<ll> A(N, 1);
  REP(i, 0, Q) {
    A[T[i]] = 1 - A[T[i]];
  }
  ll ans = accumulate(ALL(A), 0LL);
  cout << ans << endl;

  return 0;
}

