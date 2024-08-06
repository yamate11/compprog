#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/math>
using namespace atcoder;
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
    ll N, A, M; cin >> N >> A >> M;
    ll g = gcd(A, M);
    ll m0 = M / g;
    ll a0 = A / g;
    ll x = floor_sum(m0 + 1, m0, a0, 0);
    ll y = M * x + M * (m0 - 1) - m0 * (m0 + 1) * A / 2;
    ll p = N / m0;
    ll q = N % m0;
    if (q == 0) return p * y;
    else {
      ll xx = floor_sum(q + 1, m0, a0, 0);
      ll yy = M * xx + M * q - q * (q + 1) * A / 2;
      return p * y + yy;
    }

  };
  
  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

