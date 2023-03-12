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

// @@ !! LIM(doubling binsearch)

// ---- inserted library file doubling.cc

struct DoublingFRel { // from functional relation
  int n;
  vector<vector<int>> tbl;

  void _init(long long lim, auto frel) {
    int K = 64 - __builtin_clzll(lim);
    tbl.resize(K, vector<int>(n));
    for (int i = 0; i < n; i++) tbl[0][i] = frel(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < n; i++) tbl[k + 1][i] = tbl[k][tbl[k][i]];
  }

  DoublingFRel(long long lim, int n_, auto frel) : n(n_) { _init(lim, frel); }

  int val(long long x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) i = tbl[k][i];
    return i;
  }
};
  
template <typename T>
struct DoublingCum {
  const DoublingFRel& d;
  vector<vector<T>> tbl;

  void _init(auto mapping) {
    int K = d.tbl.size();
    tbl.resize(K, vector<T>(d.n));
    for (int i = 0; i < d.n; i++) tbl[0][i] = mapping(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < d.n; i++) tbl[k + 1][i] = tbl[k][i] + tbl[k][d.tbl[k][i]];
  }

  DoublingCum(const DoublingFRel& d_, auto mapping) : d(d_) { _init(mapping); }

  T val(long long x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = T();
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = ret + tbl[k][i];
        i = d.tbl[k][i];
      }
    return ret;
  }
};

// ---- end doubling.cc

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
  // @InpVec(N, X) [lu1q2RQz]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [lu1q2RQz]
  ll L, Q; cin >> L >> Q;
  vector<ll> oneday(N);
  {
    ll j = 0;
    REP(i, 0, N) {
      while (j + 1 < N and X[j + 1] - X[i] <= L) j++;
      oneday[i] = j;
    }
  }
  DoublingFRel d(N, N, [&](int i) -> int { return oneday[i]; });
  REP(_q, 0, Q) {
    ll a, b; cin >> a >> b; a--; b--;
    if (a > b) swap(a, b);
    auto check = [&](ll t) -> bool { return b <= d.val(t, a); };
    ll ans = binsearch_i<ll>(check, b - a, 0LL);
    cout << ans << endl;
  }

  return 0;
}

