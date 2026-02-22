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
  // @InpMVec(N, (X, Y, H)) [oHxRtPYK]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    ll v3; cin >> v3; H[i] = v3;
  }
  // @End [oHxRtPYK]

  auto check = [&](ll cx, ll cy, ll h) -> bool {
    if (h < 0) return false;
    REP(i, 0, N) {
      if (not (max(h - abs(X[i] - cx) - abs(Y[i] - cy), 0LL) == H[i])) return false;
    }
    return true;
  };

  REP(cx, 0, 101) REP(cy, 0, 101) REP(dh, -200, 201) {
    if (check(cx, cy, H[0] + dh)) {
      cout << cx << " " << cy << " " << H[0] + dh << endl;
      return 0;
    }
  }

  return 0;
}

