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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [Zyk38pgU]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Zyk38pgU]
  ll x = *min_element(ALL(A));
  REP(i, 0, N) A[i] -= x;
  K -= x;
  ll y = *max_element(ALL(A));
  if (K < 0 or y < K) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  ll g = 0;
  REP(i, 0, N) g = gcd(g, A[i]);
  if (g == 0) {
    cout << "POSSIBLE\n";
  }else if (K % g == 0) {
    cout << "POSSIBLE\n";
  }else {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}

