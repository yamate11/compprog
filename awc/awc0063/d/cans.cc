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
  // @InpVec(N, V) [ViXGaQCb]
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [ViXGaQCb]

  vector tbl(N, vector(N, optional<ll>()));
  auto f = [&](auto rF, ll a, ll b) -> ll {
    optional<ll>& r = tbl[a][b];
    if (not r) {
      if (a == b) r = V[a];
      else if (a < b) {
        ll x1 = V[a] - rF(rF, a + 1, b);
        ll x2 = V[b] - rF(rF, a, b - 1);
        r = max(x1, x2);
      }else assert(0);
    }
    return *r;
  };
  ll ans = f(f, 0, N - 1);
  cout << ans << endl;

  return 0;
}

