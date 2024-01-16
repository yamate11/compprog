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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [Wp4UICid]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Wp4UICid]
  // @InpMVec(M, (B, C)) [4obEqQmj]
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; B[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [4obEqQmj]
  vector<pll> vec;
  REP(i, 0, N) vec.emplace_back(A[i], 1);
  REP(i, 0, M) vec.emplace_back(C[i], B[i]);
  sort(ALL(vec), greater<pll>());
  ll ans = 0;
  ll n = 0;
  REP(i, 0, N + M) {
    auto [c, b] = vec[i];
    if (n + b <= N) {
      ans += c * b;
      n += b;
    }else {
      ans += c * (N - n);
      n = N;
    }
    if (n == N) break;
  }
  cout << ans << endl;
  return 0;
}

