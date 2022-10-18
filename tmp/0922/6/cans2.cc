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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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

  ll N; cin >> N;
  // @InpVec(N, A) [vJ8nBFud]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [vJ8nBFud]
  if (N == 1) {
    cout << A[0] << "\n" << A[0] << "\n";
    return 0;
  }
  auto check1 = [&](double x) -> bool {
    vector<double> tbl(N);
    tbl[0] = A[0] - x;
    tbl[1] = max(A[1] - x, A[0] + A[1] - 2 * x);
    REP(i, 2, N) {
      tbl[i] = max(tbl[i - 2], tbl[i - 1]) + A[i] - x;
    }
    if (tbl[N - 2] >= 0 or tbl[N - 1] >= 0) return true;
    else return false;
  };
  double x1 = binsearch_r<double>(check1, 1, 1e9 + 20, 1e-4);
  cout << x1 << endl;
  auto check2 = [&](ll x) -> bool {
    vector<ll> tbl(N);
    tbl[0] = (A[0] >= x) ? 1 : -1;
    ll p = (A[1] >= x) ? 1 : -1;
    tbl[1] = max(tbl[0] + p, p);
    REP(i, 2, N) {
      tbl[i] = max(tbl[i - 2], tbl[i - 1]) + (A[i] >= x ? 1 : -1);
    }
    return (tbl[N - 1] >= 1 or tbl[N - 2] >= 1);
  };
  ll x = binsearch_i<ll>(check2, 1, ll(1e9 + 20));
  cout << x << endl;

  return 0;
}

