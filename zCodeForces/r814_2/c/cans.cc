#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(binsearch)

// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, Q; cin >> N >> Q;
    // @InpVec(N, A, dec=1) [b7gn08Eh]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
    // @End [b7gn08Eh]
    vector<ll> B(N);
    B[0] = A[0];
    REP(i, 1, N) B[i] = max(B[i - 1], A[i]);
    REP(_q, 0, Q) {
      ll i, k; cin >> i >> k; i--;
      ll wait = max(i - 1, 0LL);
      ll j = upper_bound(ALL(B), A[i]) - B.begin();
      auto check = [&](ll a) -> bool {
        if (j < N) return wait + a < j and wait + a <= k;
        else return wait + a <= k;
      };
      ll ans = binsearch_i<ll>(check, 0, k + 1);
      cout << ans << "\n";
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

