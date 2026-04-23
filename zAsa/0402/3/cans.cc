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

  ll N, M, D; cin >> N >> M >> D;
  // @InpVec(N, A) [O8EPw0VU]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [O8EPw0VU]
  // @InpVec(M, B) [aB8IeaJ8]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [aB8IeaJ8]
  ranges::sort(A);
  ranges::sort(B);
  
  REPrev(i, N - 1, 0) {
    ll x = A[i];
    ll i0 = ranges::lower_bound(B, x - D) - B.begin();
    if (i0 < M) {
      ll j = ranges::lower_bound(B, x + D + 1) - B.begin();
      if (i0 < j) {
        cout << x + B[j - 1] << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

