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

  ll N, M; cin >> N >> M;
  // @InpVec(N, H) [gZe2J6bt]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [gZe2J6bt]
  // @InpVec(N, T) [kyYSLfxi]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [kyYSLfxi]
  vector<ll> A(N + 1);
  REP(i, 0, M) {
    ll l, r, w; cin >> l >> r >> w; l--;
    A[l] += w;
    A[r] -= w;
  }
  ll ans = 0;
  ll d = 0;
  REP(i, 0, N) {
    d += A[i];
    ll h = H[i] + d;
    if (h >= T[i]) ans++;
  }
  cout << ans << endl;


  return 0;
}

