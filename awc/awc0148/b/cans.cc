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
  // @InpMVec(N, (X, Y)) [Gx4WOrou]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
  }
  // @End [Gx4WOrou]
  map<ll, ll> R, C;
  REP(i, 0, N) {
    R[X[i]]++;
    C[Y[i]]++;
  }
  ll nx = ssize(R);
  ll ny = ssize(C);
  REP(i, 0, N) {
    ll x = R[X[i]];
    ll y = C[Y[i]];
    if (x >= 2 and y >= 2) {
      cout << nx * ny - (N - 1) << "\n";
    }else if (x >= 2) {
      cout << nx * (ny - 1) - (N - 1) << "\n";
    }else if (y >= 2) {
      cout << (nx - 1) * ny - (N - 1) << "\n";
    }else {
      cout << (nx - 1) * (ny - 1) - (N - 1) << "\n";
    }
  }



  return 0;
}

