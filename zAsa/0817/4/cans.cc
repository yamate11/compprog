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
    // @InpVec(5, A) [hDPtBeQk]
    auto A = vector(5, ll());
    for (int i = 0; i < 5; i++) { ll v; cin >> v; A[i] = v; }
    // @End [hDPtBeQk]
    // @InpVec(5, P) [gTpwvjKE]
    auto P = vector(5, ll());
    for (int i = 0; i < 5; i++) { ll v; cin >> v; P[i] = v; }
    // @End [gTpwvjKE]
    ll t = 0;
    REP(i, 0, 5) t += (i - 2) * A[i];
    if (t >= 0) return 0;
    t = -t;
    ll p4 = P[3];
    ll p5 = P[4];
    if (2 * p4 <= p5) return t * p4;
    if (t % 2 == 0) return (t / 2) * p5;
    return (t / 2) * p5 + min(p4, p5);
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";


  return 0;
}

