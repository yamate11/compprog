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

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, T; cin >> N >> T;
  // @InpVec(N, A) [Cgqcnuio]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Cgqcnuio]

  auto f = [&](ll lo, ll hi) -> vector<ll> {
    vector<ll> ret;
    REP(x, 0, 1LL << (hi - lo)) {
      ll s = 0;
      REP(i, 0, hi - lo) if (x >> i & 1) {
        s += A[lo + i];
      }
      if (s <= T) ret.push_back(s);
    }
    ranges::sort(ret);
    return ret;
  };

  auto vec1 = f(0, N / 2);
  auto vec2 = f(N / 2, N);

  ll ans = 0;
  ll j = 0;
  REPrev(i, ssize(vec1) - 1, 0) {
    if (j == ssize(vec2)) break;
    while (true) {
      if (j == ssize(vec2)) break;
      ll val = vec1[i] + vec2[j];
      if (val > T) break;
      updMax(ans, val);
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}

