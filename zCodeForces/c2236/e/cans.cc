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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A, dec=1) [YyAvmphL]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [YyAvmphL]

    vector Bmax(N, vector(N + 1, -1));
    vector Bmin(N, vector(N + 1, (int)N));
    REP(i, 0, N) {
      vector C(N, false);
      ll vmax = -1;
      ll vmin = N;
      REP(j, i, N) {
        ll x = A[j];
        if (C[x]) break;
        C[x] = true;
        vmax = max(vmax, x);
        vmin = min(vmin, x);
        if (vmax == vmin + (j - i)) {
          ll len = vmax - vmin + 1;
          Bmax[vmin][len] = max(Bmax[vmin][len], (int)i);
          Bmin[vmin][len] = min(Bmin[vmin][len], (int)i);
        }
      }
    }
    REPrev(len, N/2, 0) {
      REP(a, 0, N) {
        if (a + 2 * len > N) break;
        if (Bmin[a][len] + len <= Bmax[a + len][len] or Bmin[a + len][len] + len <= Bmax[a][len]) {
          cout << len << "\n";
          return ;
        }
      }
    }
    cout << 0 << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

