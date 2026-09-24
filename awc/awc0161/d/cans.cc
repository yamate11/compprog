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
  // @InpVec(N, A) [b4xXTKZ2]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [b4xXTKZ2]
  
  if (N == 1) {
    cout << A[0] << "\n";
  }else if (N % 2 == 0) {
    cout << max(A[N/2 - 1], A[N/2]) << "\n";
  }else {
    ll a = A[N/2 - 1], b = A[N/2], c = A[N/2 + 1];
    ll ans;
    if (a >= b and b <= c) ans = b;
    else if (a <= b and b >= c) ans = max(a, c);
    else ans = b;
    cout << ans << "\n";
  }

  return 0;
}

