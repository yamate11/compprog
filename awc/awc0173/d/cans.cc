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
  // @InpVec(M, H) [fkb4j5sR]
  auto H = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; H[i] = v; }
  // @End [fkb4j5sR]

  vector<ll> diff(M + 1);
  REP(i, 0, N) {
    ll l, r, a; cin >> l >> r >> a; l--;
    diff[l] += a;
    diff[r] -= a;
  }
  ll cur = 0;
  ll ans = 0;
  REP(i, 0, M) {
    cur += diff[i];
    if (cur >= H[i]) ans++;
  }
  cout << ans << "\n";
  return 0;
}

