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

  ll N; cin >> N;
  // @InpVec(N, A) [8fWYKRTx]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [8fWYKRTx]

  vector<ll> left(N), right(N);
  left[1] = A[0];
  REP(i, 2, N) left[i] = gcd(left[i - 1], A[i - 1]);
  right[N - 2] = A[N - 1];
  REPrev(i, N - 3, 0) right[i] = gcd(right[i + 1], A[i + 1]);
  ll ans = max(right[0], left[N - 1]);
  REP(i, 1, N - 1) ans = max(ans, gcd(left[i], right[i]));
  cout << ans << endl;


  return 0;
}

