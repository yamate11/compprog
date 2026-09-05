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

  ll N, M, K; cin >> N >> M >> K;
  // @InpVec(N, L) [uaMEyaVQ]
  auto L = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; L[i] = v; }
  // @End [uaMEyaVQ]
  vector<ll> diff(N + 1, 0LL);
  REP(i, 0, M) {
    ll x, y, z; cin >> x >> y >> z; x--;
    diff[x] += z;
    diff[y] -= z;
  }
  ll ans = 0;
  ll cur = 0;
  REP(i, 0, N) {
    cur += diff[i];
    if (L[i] + cur >= K) ans++;
  }
  cout << ans << "\n";
  return 0;
}

