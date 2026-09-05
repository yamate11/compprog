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
  // @InpVec(N, A) [P83cVnVU]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [P83cVnVU]
  ranges::sort(A);
  if (K % 2 == 0) {
    ll m = K / 2;
    ll s1 = 0;
    REP(i, 0, m - 1) s1 += 2 * A[N - 1 - i];
    s1 += A[N - 1 - (m - 1)];
    s1 += A[N - 1 - m];
    REP(i, 0, m) s1 -= 2 * A[i];
    ll s2 = 0;
    REP(i, 0, m) s2 += 2 * A[N - 1 - i];
    REP(i, 0, m - 1) s2 -= 2 * A[i];
    s2 -= A[m - 1];
    s2 -= A[m];
    ll s = max(s1, s2);
    cout << s << "\n";
  }else {
    ll s = 0;
    ll m = K / 2;
    REP(i, 0, m) {
      s += 2 * A[N - 1 - i];
      s -= 2 * A[i];
    }
    s += A[N - 1 - m];
    s -= A[m];
    cout << s << "\n";
  }

  return 0;
}

