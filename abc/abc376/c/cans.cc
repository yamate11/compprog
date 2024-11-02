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
  // @InpVec(N, A) [IwgYX3x0]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [IwgYX3x0]
  // @InpVec(N - 1, B) [22NpycBq]
  auto B = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; B[i] = v; }
  // @End [22NpycBq]

  sort(ALL(A));
  sort(ALL(B));
  ll ans = A[0];
  REP(i, 1, N) {
    if (A[i] > B[i - 1]) {
      if (A[i - 1] > B[i - 1]) {
        cout << -1 << endl;
        return 0;
      }
      ans = A[i];
    }
  }
  cout << ans << endl;

  return 0;
}

