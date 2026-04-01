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
    ll N, M, L; cin >> N >> M >> L;
    // @InpVec(N, A, dec=1) [JgQTKq0i]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [JgQTKq0i]

    vector val(M, 0LL);
    ll idx = 0;
    REP(i, 0, L) {
      ll k = N - idx;
      ll keep = min(k + 1, M);
      ll i0 = min_element(val.begin(), val.begin() + keep) - val.begin();
      val[i0]++;
      if (idx < N and A[idx] == i) {
        ll j0 = max_element(val.begin(), val.end()) - val.begin();
        val[j0] = 0;
        if (j0 < keep - 1) swap(val[j0], val[keep - 1]);
        idx++;
      }
    }
    cout << val[0] << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

