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
  // @InpMVec(Q, ((H, type=char), (T, dec=1))) [GfEc6CoR]
  auto H = vector(Q, char());
  auto T = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    char v1; cin >> v1; H[i] = v1;
    ll v2; cin >> v2; v2 -= 1; T[i] = v2;
  }
  // @End [GfEc6CoR]

  auto f = [&](ll a, ll b, ll c) -> ll {
    if (a > b) swap(a, b);
    if (a == b) return 0;
    if (a < c and c < b) return a + N - b;
    else return b - a;
  };

  ll left = 0, right = 1;
  ll ans = 0;
  REP(i, 0, Q) {
    if (H[i] == 'L') {
      ans += f(left, T[i], right);
      left = T[i];
    }else if (H[i] == 'R') {
      ans += f(right, T[i], left);
      right = T[i];
    }else assert(0);
  }
  cout << ans << endl;

  return 0;
}

