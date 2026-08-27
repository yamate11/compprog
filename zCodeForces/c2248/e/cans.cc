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
    ll N, M, D; cin >> N >> M >> D;
    // @InpMVec(M, ((P, dec=1), R)) [GuhLByK3]
    auto P = vector(M, ll());
    auto R = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; P[i] = v1;
      ll v2; cin >> v2; R[i] = v2;
    }
    // @End [GuhLByK3]
    
    if (M == 0) {
      cout << "NO\n";
      return;
    }

    vector<ll> S(2*M + 10);
    REP(i, 0, 2*M + 9) S[i + 1] = S[i] + R[i % M];
    P.resize(2*M + 10);
    REP(i, M, 2*M + 10) P[i] = N + P[i - M];
    REP(i, 0, M) {
      REP(j, 0, M) {
        ll me = -D + S[j + 1];
        ll idx_cur = (ranges::lower_bound(P, P[i] + 2 + P[j] + 1) - P.begin()) - 1;
        ll you = S[idx_cur + 1] - S[i + 1];
        if (you < me) {
          cout << "YES\n";
          return;
        }
      }
    }
    cout << "NO\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

