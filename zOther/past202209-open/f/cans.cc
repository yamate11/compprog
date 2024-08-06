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

  ll N; cin >> N;
  // @InpVec(N, A) [2fJe9Asx]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [2fJe9Asx]
  ll lim = 2e5;
  vector X(N, vector(lim, false));
  REP(i, 0, N) {
    ll c; cin >> c;
    REP(j, 0, c) {
      ll x; cin >> x; x--;
      X[i][x] = true;
    }
  }
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll d; cin >> d;
    vector vec(N, false);
    REP(j, 0, d) {
      ll y; cin >> y; y--;
      REP(i, 0, N) {
        if (X[i][y]) vec[i] = true;
      }
    }
    ll vmax = -1, i0 = -1;
    REP(i, 0, N) {
      if (vec[i] == false) {
        if (vmax < A[i]) {
          vmax = A[i];
          i0 = i;
        }
      }
    }
    if (i0 < 0) {
      cout << -1 << "\n";
    }else {
      cout << i0 + 1 << "\n";
    }
  }

  return 0;
}

