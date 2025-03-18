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

  ll N, L; cin >> N >> L;
  // @InpVec(N, A) [wAXRiYnj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wAXRiYnj]

  if (N == 1) {
    ll x = max(A[0], L - A[0]);
    cout << 4 * x << endl;
    return 0;
  }

  vector<ll> B(2*N + 1);
  B[0] = 0;
  REP(i, 1, N) B[i] = B[i - 1] + A[i] - A[i - 1];
  B[N] = B[N - 1] + 2 * (L - A[N - 1]);
  REP(i, 1, N) B[N + i] = B[N + i - 1] + A[N - i] - A[N - i - 1];
  B[2*N] = B[2*N - 1] + 2 * A[0];
  assert(B[2 * N] == 2 * L);
  ll ans = 1e18;
  ll q = 0;
  REP(p, 0, N) {
    while (B[q + 1] <= L) q++;
    if (B[q + 1] == L) {
      cout << 2 * L << endl;
      return 0;
    }
    ll x = L - B[q];
    ll y = B[q + 1] - B[q] - x;
    ll z = min(x, y);
    ans = min(ans, 2 * L + z);
  }
  cout << ans << endl;

  return 0;
}

