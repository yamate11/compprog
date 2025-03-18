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

  ll N, S; cin >> N >> S;
  // @InpVec(N, A) [jw0bTxqj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [jw0bTxqj]
  vector<ll> B(2*N + 1);
  REP(i, 0, 2*N) B[i + 1] = B[i] + A[i % N];
  ll R = S % B[N];
  ll p = 0;
  ll q = 0;
  while (true) {
    while (q < 2*N + 1 and B[q] - B[p] < R) q++;
    if (q == 2*N + 1) break;
    if (B[q] - B[p] == R) {
      cout << "Yes\n";
      return 0;
    }
    p++;
  }
  cout << "No\n";

  return 0;
}

