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

// @@ !! LIM(binsearch)

// ---- inserted library file binsearch.cc

template <typename T>
requires integral<T>
T binsearch(auto check, T yes, T no) {
  while (abs(no - yes) > 1) {
    T mid = yes + (no - yes) / 2;  // avoiding unnecessary overflow
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template <typename T>
requires floating_point<T>
T binsearch(auto check, T yes, T no, T err, const bool abs_only = false) {
  T rep_in_t = ceil(log(abs(yes - no) / err) / log(2.0));
  constexpr int lim = INT_MAX - 10;
  int rep = rep_in_t > (T)lim ? lim : llround(rep_in_t) + 1;
  for (int r = 0; r < rep; r++) {
    T mid = (yes + no) / 2.0;
    if (not abs_only) {
      if (abs(yes - mid) < err * min(abs(mid), abs(yes))) return mid;
    }
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n, k; cin >> n >> k;
    // @InpVec(n, a) [kayphEiv]
    auto a = vector(n, ll());
    for (int i = 0; i < n; i++) { ll v; cin >> v; a[i] = v; }
    // @End [kayphEiv]

    auto f = [&](ll v0) -> pll {
      vector<ll> S(n + 1), T(n + 1), J(n + 1);
      REP(i, 0, n) S[i + 1] = S[i] + (a[i] >= v0 ? 1 : -1);
      T[n] = S[n];
      J[n] = n;
      REPrev(i, n - 1, 0) {
        if (S[i] > T[i + 1]) {
          T[i] = S[i];
          J[i] = i;
        }else {
          T[i] = T[i + 1];
          J[i] = J[i + 1];
        }
      }
      REP(i, 0, n) {
        if (i + k <= n and 0 <= T[i + k] - S[i]) return pll(i, J[i + k]);
      }
      return pll(-1, -1);
    };
    auto check = [&](ll v0) -> bool {
      auto [lo, hi] = f(v0);
      return lo >= 0;
    };
    ll v0 = binsearch<ll>(check, 1, n + 1);
    auto [lo, hi] = f(v0);
    cout << v0 << " " << lo + 1 << " " << hi << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

