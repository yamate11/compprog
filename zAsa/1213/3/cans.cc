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

  ll th = 1e8;

  ll N; cin >> N;
  // @InpVec(N, A) [qYF9e7PZ]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [qYF9e7PZ]
  sort(ALL(A));

  ll U = 0;
  REP(i, 0, N) U += (2 * A[i] >= th ? 2 * A[i] - th : 2 * A[i]);

  ll V = accumulate(ALL(A), 0LL) * N * 2;

  ll M = 0;
  REP(i, 0, N) {
    ll k = A.end() - ranges::lower_bound(A, th - A[i]);
    M += k;
  }

  ll T = V - th * M;
  ll S = (T - U) / 2;
  cout << S << endl;

  return 0;
}

