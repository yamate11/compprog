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

  auto solve = [&]() -> bool {
    ll N, K; cin >> N >> K;
    // @InpVec(N, A, dec=1) [78j1GTTq]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [78j1GTTq]
    // @InpVec(N, B, dec=1) [f0gDkP5g]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
    // @End [f0gDkP5g]
    vector<ll> cntA(N, 0LL);
    vector<ll> cntB(N, 0LL);
    REP(i, 0, K) {
      auto all_match = [&]() -> bool {
        for (ll j = i; j < N; j += K) if (B[j] >= 0 and B[j] != A[j]) return false;
        return true;
      };
      auto all_same_A = [&]() -> bool {
        for (ll j = i; j < N; j+= K) if (A[j] != A[i]) return false;
        return true;
      };
      auto inspect_B = [&]() -> ll {
        ll v = -2;
        for (ll j = i; j < N; j+= K) {
          if (B[j] >= 0) {
            if (v < 0) v = B[j];
            else if (B[j] != v) return -4;
          }
        }
        return v;
      };
      if (all_same_A()) {
        ll v = inspect_B();
        if (v == -4) return false;
        cntA[A[i]]++;
        if (v >= 0) cntB[v]++;
      }else {
        if (not all_match()) return false;
      }
    }
    REP(i, 0, N) if (cntB[i] > cntA[i]) return false;
    return true;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

