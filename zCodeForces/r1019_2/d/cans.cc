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
    // @InpVec(N, A) [hxP3p4hl]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [hxP3p4hl]
    vector vec(N + 1, vector<ll>());
    REP(i, 0, N) {
      if (A[i] == -1) vec[0].push_back(i);
      else vec[A[i]].push_back(i);
    }
    ll piv = vec[0][0];
    ll hi = N;
    ll lo = 1;
    vector<ll> ans(N);
    REP(i, 1, N + 1) {
      if (vec[i].empty()) break;
      if (i % 2 == 0) {
        while (not vec[i].empty()) {
          ll j = vec[i].back();
          if (j < piv) break;
          vec[i].pop_back();
          ans[j] = lo++;
        }
        for (ll j : vec[i]) {
          ans[j] = lo++;
        }
      }else {
        while (not vec[i].empty()) {
          ll j = vec[i].back();
          if (j < piv) break;
          vec[i].pop_back();
          ans[j] = hi--;
        }
        for (ll j : vec[i]) {
          ans[j] = hi--;
        }
      }
    }
    assert(lo == hi);
    ans[piv] = lo;
    REPOUT(i, 0, N, ans[i], " ");
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

