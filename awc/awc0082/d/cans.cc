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
// published at https://github.com/yamate11/compprog-clib/blob/master/binsearch.cc

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

  ll N, L, Q; cin >> N >> L >> Q;
  // @InpMVec(N, (A, R, V)) [911xvDUj]
  auto A = vector(N, ll());
  auto R = vector(N, ll());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
    ll v3; cin >> v3; V[i] = v3;
  }
  // @End [911xvDUj]
  REP(_q, 0, Q) {
    ll t, s, p; cin >> t >> s >> p;
    auto f = [&](ll x) -> ll {
      ll ret = 0;
      REP(i, 0, N) {
        ll alpha = x / A[i];
        ll beta = x % A[i];
        ll rock = (R[i] + V[i] * t) % A[i];
        ret += alpha + (rock <= beta ? 1 : 0);
      }
      return ret;
    };
    auto check1 = [&](ll x) -> bool {
      return f(x) - f(s) <= p;
    };
    ll x1 = binsearch<ll>(check1, s, L);
    auto check2 = [&](ll x) -> bool {
      return f(s) - f(x) <= p;
    };
    ll x2 = binsearch<ll>(check2, s, -1LL);
    cout << x1 - x2 + 1 << "\n";
  }

  return 0;
}

