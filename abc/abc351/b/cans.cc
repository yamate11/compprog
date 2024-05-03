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
  // @InpVec(N, A, type=string) [PyrYyO9I]
  auto A = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; A[i] = v; }
  // @End [PyrYyO9I]
  // @InpVec(N, B, type=string) [Q0Z0d7HV]
  auto B = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; B[i] = v; }
  // @End [Q0Z0d7HV]

  REP(i, 0, N) REP(j, 0, N) {
    if (A[i][j] != B[i][j]) {
      cout << i + 1 << " " << j + 1 << endl;
      return 0;
    }
  }

  return 0;
}

