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
    ll N, K; cin >> N >> K;
    // @InpVec(N, A) [rJDo6fU3]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [rJDo6fU3]
    // @InpVec(K, P, dec=1) [jVo4oEif]
    auto P = vector(K, ll());
    for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
    // @End [jVo4oEif]
    vector<ll> vec(K + 1, 0LL);
    REP(i, 0, K + 1) {
      ll j0 = i == 0 ? 0 : P[i - 1];
      ll j1 = i == K ? N - 1 : P[i];
      REP(j, j0, j1) if (A[j] != A[j + 1]) vec[i]++;
    }
    ll tot = accumulate(ALL(vec), 0LL);
    ll jm = max_element(ALL(vec)) - vec.begin();
    ll vm = vec[jm];
    ll ans = -1;
    if (vm <= tot - vm) {
      if (vec.front() % 2 == 0 and vec.back() % 2 == 0) ans = tot / 2;
      else if (vec.front() % 2 != 0 and vec.back() % 2 != 0) ans = tot / 2 + 1;
      else ans = (tot - 1) / 2 + 1;
    }else {
      if (vm % 2 == 0) ans = vm;
      else ans = vm + 1;
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

