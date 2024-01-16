#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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
  // @InpGrid(N, 10, F) [0Q6A457D]
  auto F = vector(N, vector(10, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < 10; j++) { ll v; cin >> v; F[i][j] = v; }
  // @End [0Q6A457D]
  // @InpGrid(N, 11, P) [e1NQif4c]
  auto P = vector(N, vector(11, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < 11; j++) { ll v; cin >> v; P[i][j] = v; }
  // @End [e1NQif4c]
  
  ll ans = -1e18;
  REP(x, 1, 1LL << 10) {
    ll p = 0;
    REP(i, 0, N) {
      ll n = 0;
      REP(k, 0, 10) {
        if ((x >> k & 1) and F[i][k]) n++;
      }
      p += P[i][n];
    }
    ans = max(ans, p);
  }
  cout << ans << endl;
  return 0;
}

