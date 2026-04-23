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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    // @InpMVec(N, (W, P)) [1P16mBny]
    auto W = vector(N, ll());
    auto P = vector(N, ll());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; W[i] = v1;
      ll v2; cin >> v2; P[i] = v2;
    }
    // @End [1P16mBny]

    vector<ll> A(N);
    REP(i, 0, N) A[i] = P[i] + W[i];
    ranges::sort(A);
    ll x = accumulate(ALL(P), 0LL);
    ll s = 0;
    REP(i, 0, N) {
      s += A[i];
      if (s > x) return i;
    }
    return N;

  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

