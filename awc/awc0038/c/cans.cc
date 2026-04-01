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

  ll N, L, K; cin >> N >> L >> K;
  // @InpVec(N, A) [5tkHUsFn]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5tkHUsFn]
  ranges::sort(A);
  ll x = 0;
  REP(i, 0, K) {
    if (x + A[i] <= L) {
      x += A[i];
    }else {
      cout << i << endl;
      return 0;
    }
  }
  if (K + 1 <= N and x + A[K] <= L) {
    cout << K + 1 << endl;
  }else {
    cout << K << endl;
  }
  return 0;
}

