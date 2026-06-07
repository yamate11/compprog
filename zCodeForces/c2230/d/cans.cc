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
    // @InpVec(N, A) [kMDvvaU1]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [kMDvvaU1]
    // @InpVec(N, B) [et2Kj6w6]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [et2Kj6w6]

    ll score = 0;
    ll tot = 0;
    vector W(N + 2, 0LL);
    if (A[0] == 1 and B[0] == 1) {
      W[2] = 1;
      tot = 1;
    }else if (A[0] == 1) {
      // nothing to do
    }else if (B[0] == 1) {
      // nothing to do
    }else {
      W[1] = 1;
      tot = 1;
    }
    score = tot;
    REP(i, 1, N) {
      if (A[i] == B[i]) {
        ll x = A[i];
        W[x + 1] += W[x];
        W[x] = 0;
        if (x == 1) {
          W[2] += 1;
          tot += 1;
        }else {
          W[1] += 1;
          tot += 1;
        }
      }else {
        tot -= W[A[i]];
        W[A[i]] = 0;
        tot -= W[B[i]];
        W[B[i]] = 0;
        if (A[i] == 1 or B[i] == 1) {
          // nothing to do
        }else {
          W[1] += 1;
          tot += 1;
        }
      }
      score += tot;
    }
    cout << score << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

