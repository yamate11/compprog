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
  // @InpVec(N, A) [ozRo693v]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [ozRo693v]

  auto f = [&](auto rF, u64 x) -> set<ll> {
    ll m = bit_width(x) - 1;
    u64 x0 = x ^ (1ULL << m);
    if (x0 == 0) {
      return set<ll>{A[m]};
    }
    if (popcount(x0) == 1) {
      ll t = countr_zero(x0);
      return set<ll>{A[m] ^ A[t], A[m] + A[t]};
    }
    set<ll> ret;
    {
      ll s = 0;
      REP(i, 0, m) if (x0 >> i & 1) s += A[i];
      ret.insert(A[m] + s);
    }
    u64 y = x0;
    while (true) {
      if (y == 0) break;
      y = x0 & (y - 1);
      ll s = 0;
      REP(i, 0, m) if (y >> i & 1) s += A[i];
      auto r = rF(rF, x0 ^ y);
      for (auto z : r) {
        ret.insert((A[m] + s) ^ z);
      }
    }
    return ret;
  };
  auto ans = f(f, (1ULL << N) - 1);
  cout << ssize(ans) << endl;

  return 0;
}

