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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, A) [CuFPYyCj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [CuFPYyCj]
  vector B(2 * N + 1, 0LL);
  REP(i, 0, N) B[i + 1] = B[i] + A[i];
  REP(i, 0, N) B[N + i + 1] = B[N + i] + A[i];
  
  ll head = 0;
  REP(_q, 0, Q) {
    ll tp; cin >>tp;
    if (tp == 1) {
      ll c; cin >> c;
      head = (head + c) % N;
    }else if (tp == 2) {
      ll l, r; cin >> l >> r; l--;
      ll l0 = head + l;
      ll r0 = head + r;
      cout << B[r0] - B[l0] << "\n";
    }else assert(0);
  }

  return 0;
}

