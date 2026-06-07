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

  ll N, K, M, X; cin >> N >> K >> M >> X;
  // @InpVec(M, Y) [usDLIKMc]
  auto Y = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; Y[i] = v; }
  // @End [usDLIKMc]
  
  REP(k, 0, K) {
    if (X >> 0 & 1) break;
    X = (X >> 1) | (1LL << (N - 1));
  }
  ll ans = 0;
  REP(p, 1, N) {
    auto left = [&](ll x) -> ll { return x & ((1LL << p) - 1); };
    auto right = [&](ll x) -> ll { return x >> p; };
    ll A = left(X);
    ll B = right(X);
    REP(i, 0, M) {
      A += left(Y[i]);
      B += right(Y[i]);
    }
    ans = max(ans, A + B);
  }
  cout << ans << endl;
  return 0;
}

