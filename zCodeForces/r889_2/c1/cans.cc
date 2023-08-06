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
    // @InpVec(N, A) [LHscIExm]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [LHscIExm]
    ll t = -1;
    ll i0 = -1;
    REP(i, 0, N) {
      if (abs(A[i]) > t) {
        i0 = i;
        t = abs(A[i]);
      }
    }
    if (A[i0] == 0) {
      cout << 0 << "\n";
      return;
    }
    vector<ll> B;
    vector<ll> C;
    REP(i, 0, N) {
      if (i != i0) {
        B.push_back(i);
        C.push_back(i0);
      }
    }
    if (A[i0] > 0) {
      REP(i, 1, N) {
        B.push_back(i);
        C.push_back(i - 1);
      }
    }else {
      REPrev(i, N - 2, 0) {
        B.push_back(i);
        C.push_back(i + 1);
      }
    }
    cout << SIZE(B) << "\n";
    REP(i, 0, SIZE(B)) {
      cout << B[i] + 1 << " " << C[i] + 1 << "\n";
    }


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

