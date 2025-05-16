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
    // @InpMVec(N, (X, Y)) [2GXZpkiB]
    auto X = vector(N, ll());
    auto Y = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; X[i] = v1;
      ll v2; cin >> v2; Y[i] = v2;
    }
    // @End [2GXZpkiB]
    REP(i, 0, N) Y[i] += X[i];
    map<ll, ll> mpx, mpy;
    REP(i, 0, N) {
      mpx[X[i]]++;
      mpy[Y[i]]++;
    }
    ll x0, y0;
    for (auto [x, n] : mpx) {
      if (n % 2 != 0) x0 = x;
    }
    for (auto [y, n] : mpy) {
      if (n % 2 != 0) y0 = y;
    }
    y0 -= x0;
    cout << x0 << " " << y0 << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

