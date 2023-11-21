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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpMVec(N, ((L, dec=1), R)) [AZCTR5dZ]
    auto L = vector(N, ll());
    auto R = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; v1 -= 1; L[i] = v1;
      ll v2; cin >> v2; R[i] = v2;
    }
    // @End [AZCTR5dZ]
    auto func = [&]() -> ll {
      enum Kind { OUT, IN };
      using sta = pair<ll, Kind>;
      vector<sta> ev;
      REP(i, 0, N) {
        if (R[i] == M) continue;
        ev.emplace_back(L[i], IN);
        ev.emplace_back(R[i], OUT);
      }
      sort(ALL(ev));
      ll dup = 0;
      ll vmax = 0;
      for (auto [t, kind] : ev) {
        if (kind == IN) {
          dup++;
          vmax = max(vmax, dup);
        }else if (kind == OUT) {
          dup--;
        }else assert(0);
      }
      return vmax;
    };

    ll a = func();
    REP(i, 0, N) {
      ll x = M - L[i];
      ll y = M - R[i];
      L[i] = y;
      R[i] = x;
    }
    ll b = func();
    return max(a, b);

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

