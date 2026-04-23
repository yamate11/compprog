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

  auto solve = [&]() -> vector<ll> {
    vector<ll> ret;
    ll N; cin >> N;
    // @InpVec(N, P, dec=1) [gk0w6TNj]
    auto P = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
    // @End [gk0w6TNj]
    // @InpVec(N, D) [ePmzv3Hs]
    auto D = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
    // @End [ePmzv3Hs]
    vector W(N, 0LL);
    REP(i, 0, N) {
      REP(j, i + 1, N) if (P[i] < P[j]) W[i]++;
      if (W[i] < D[i]) return ret;
    }
    vector<ll> vec(N);
    REPrev(i, N - 1, 0) {
      ll cnt = 0;
      REPrev(j, N - 1 - i, 0) {
        if (cnt == D[i]) {
          vec[j] = i;
          break;
        }
        assert(j > 0);
        vec[j] = vec[j - 1];
        if (P[i] < P[vec[j]]) cnt++;
      }
    }
    ret = vector<ll>(N);
    REP(i, 0, N) ret[vec[i]] = i;
    return ret;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) {
    auto vec = solve();
    if (vec.empty()) {
      cout << -1 << "\n";
    }else {
      REPOUT(i, 0, ssize(vec), vec[i] + 1, " ");
    }
  }

  return 0;
}

