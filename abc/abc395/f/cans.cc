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

  ll N, X; cin >> N >> X;
  // @InpMVec(N, (U, D)) [rTf1lDoH]
  auto U = vector(N, ll());
  auto D = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; U[i] = v1;
    ll v2; cin >> v2; D[i] = v2;
  }
  // @End [rTf1lDoH]

  ll big = 1e18;
  ll vmin = big;
  REP(i, 0, N) vmin = min(vmin, U[i] + D[i]);


  auto check = [&](ll p) -> bool {
    ll lo = 0;
    ll hi = p;
    REP(i, 0, N) {
      ll tlo = p - D[i];
      ll thi = U[i];
      if (i == 0) {
        lo = tlo;
        hi = thi;
      }else {
        ll xlo = max(0LL, lo - X);
        ll xhi = min(p, hi + X);
        lo = max(xlo, tlo);
        hi = min(xhi, thi);
      }
      if (hi < lo) return false;
    }
    return true;
  };
  ll p = binsearch<ll>(check, 0, vmin + 1);
  ll ans = 0;
  REP(i, 0, N) ans += U[i] + D[i] - p;
  cout << ans << endl;

  return 0;
}

