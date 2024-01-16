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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

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

  ll N, M; cin >> N >> M;
  // @InpVec(M, X, dec=1) [QPnATnht]
  auto X = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; X[i] = v; }
  // @End [QPnATnht]
  
  if (M == N) {
    cout << 0 << endl;
    return 0;
  }

  auto check = [&](ll x) -> bool {
    ll n = N;
    REPrev(m, M - 1, 0) {
      if (n - 1 <= X[m]) {
        n = X[m] - x;
      }else {
        ll right = n - 1 - X[m];
        if (x < right) return false;
        ll n1;
        if (x <= 2 * right) n1 = X[m];
        else n1 = X[m] - (x - 2 * right);
        ll xx = (x - right) / 2;
        ll n2 = X[m] - xx;
        n = min(n1, n2);
      }
      if (n <= 0) return true;
    }
    return false;
  };
  ll ans = binsearch_i<ll>(check, 2*N, -1);
  cout << ans << endl;

  return 0;
}

