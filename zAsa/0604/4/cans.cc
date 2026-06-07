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

  ll N, M, P; cin >> N >> M >> P;
  // @InpVec(N, A) [Og4nlGad]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Og4nlGad]
  // @InpVec(M, B) [jiVgwLdH]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [jiVgwLdH]
  ranges::sort(B);
  vector<ll> BS(M + 1);
  REP(i, 0, M) BS[i + 1] = BS[i] + B[i];

  ll ans = 0;
  REP(i, 0, N) {
    if (A[i] >= P) ans += P * M;
    else {
      ll j0 = ranges::lower_bound(B, P - A[i]) - B.begin();
      ans += A[i] * j0 + BS[j0] + P * (M - j0);
    }
  }
  cout << ans << endl;
  return 0;
}

