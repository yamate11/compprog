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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, P, Q, R; cin >> N >> M >> P >> Q >> R;
  vector Z(N, vector(M, 0LL));
  REP(i, 0, R) {
    ll x, y, z; cin >> x >> y >> z; x--; y--;
    Z[x][y] = z;
  }
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    if (__builtin_popcountll(x) != P) continue;
    vector vec(M, 0LL);
    REP(i, 0, N) if (x >> i & 1) {
      REP(j, 0, M) vec[j] += Z[i][j]; 
    }
    sort(ALL(vec), greater<ll>());
    ll a = accumulate(vec.begin(), vec.begin() + Q, 0LL);
    ans = max(ans, a);
  }
  cout << ans << endl;

  return 0;
}

