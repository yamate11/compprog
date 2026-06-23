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
  // @InpVec(N, S) [f7iBgW3f]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [f7iBgW3f]
  // @InpVec(N, C) [vH0kxbpO]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [vH0kxbpO]

  vector<bool> closed(N, false);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll l, r, v; cin >> l >> r >> v; l--;
      REP(i, l, r) if (not closed[i]) {
        C[i] += v;
      }
    }else if (tp == 2) {
      ll x; cin >> x; x--;
      closed[x] = true;
    }else if (tp == 3) {
      ll l, r; cin >> l >> r; l--;
      ll ans = 0;
      REP(i, l, r) if (not closed[i] and C[i] <= 0) {
        ans += S[i];
      }
      cout << ans << "\n";
    }
  }

  return 0;
}

