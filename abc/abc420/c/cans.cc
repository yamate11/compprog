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
  // @InpVec(N, A) [fYLXgYmD]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fYLXgYmD]
  // @InpVec(N, B) [uaicTYUV]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [uaicTYUV]

  ll ans = 0;
  REP(i, 0, N) ans += min(A[i], B[i]);

  REP(_q, 0, Q) {
    char c; cin >> c;
    ll x, v; cin >> x >> v; x--;
    if (c == 'A') {
      ll old_min = min(A[x], B[x]);
      ll new_min = min(v,    B[x]);
      ans += new_min - old_min;
      A[x] = v;
    }else if (c == 'B') {
      ll old_min = min(A[x], B[x]);
      ll new_min = min(A[x], v);
      ans += new_min - old_min;
      B[x] = v;
    }else assert(0);
    cout << ans << "\n";
  }

  return 0;
}

