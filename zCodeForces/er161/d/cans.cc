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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [CNkDedjR]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [CNkDedjR]
    // @InpVec(N, D) [sVrIj3Fc]
    auto D = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; D[i] = v; }
    // @End [sVrIj3Fc]
    
    // vector dl(N, true);
    set<ll> live;
    REP(i, 0, N) live.insert(i);

    set<ll> chk;
    REP(i, 0, N) chk.insert(i);
    vector<ll> ans(N);
    REP(n, 0, N) {
      auto prv = move(chk);
      chk = set<ll>();
      set<ll> willdie;
      for (ll i : prv) {
        auto it = live.find(i);
        ll dmg = 0;
        if (it != live.end()) {
          ll j = -1;
          if (it != live.begin()) {
            j = *std::prev(it);
            dmg += A[j];
          }
          ll k = -1;
          auto it2 = std::next(it);
          if (it2 != live.end()) {
            k = *it2;
            dmg += A[k];
          }
          if (dmg > D[i]) {
            willdie.insert(i);
            if (j >= 0) chk.insert(j);
            if (k >= 0) chk.insert(k);
          }
        }
      }
      ans[n] = SIZE(willdie);
      for (ll i : willdie) {
        live.erase(i);
      }
    }
    REPOUT(i, 0, N, ans[i], " ");

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

