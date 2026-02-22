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
    ll N, M, K; cin >> N >> M >> K;
    // @InpVec(N, R) [r6qblaAR]
    auto R = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
    // @End [r6qblaAR]
    // @InpVec(M, P) [DV9kwCel]
    auto P = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; P[i] = v; }
    // @End [DV9kwCel]
    ranges::sort(R, greater<ll>());
    ranges::sort(P, greater<ll>());

    auto f = [&](const auto& vec, ll n) -> ll {
      return accumulate(vec.begin(), vec.begin() + n, 0LL);
    };

    if (K % 2 == 0) {
      ll H = K / 2;
      if (N >= H and M >= H) return f(R, H) + f(P, H);
      else return -1;
    }else {
      ll H1 = K / 2;
      ll H2 = K - H1;
      ll ans = -1LL;
      if (N >= H1 and M >= H2) ans = max(ans, f(R, H1) + f(P, H2));
      if (N >= H2 and M >= H1) ans = max(ans, f(R, H2) + f(P, H1));
      return ans;
    }

  };
  cout << solve() << "\n";

  return 0;
}

