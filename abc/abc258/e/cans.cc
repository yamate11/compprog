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

// @@ !! LIM(doubling)

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
  static DoublingFRel from_container(long long lim, int n, auto vec) {
    return DoublingFRel(lim, n, [&](int i) { return vec[i]; });
  }

  int val(long long x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) i = tbl[k][i];
    return i;
  }
};
  
template <typename T, typename add_t>
struct DoublingCum {
  const DoublingFRel& d;
  T unit;
  add_t add;
  vector<vector<T>> tbl;

  void _init(auto mapping) {
    int K = d.tbl.size();
    tbl.resize(K, vector<T>(d.n));
    for (int i = 0; i < d.n; i++) tbl[0][i] = mapping(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < d.n; i++) tbl[k + 1][i] = add(tbl[k][i], tbl[k][d.tbl[k][i]]);
  }

  DoublingCum(const DoublingFRel& d_, auto mapping, T unit_, add_t add_)
    : d(d_), unit(unit_), add(add_) { _init(mapping); }

  T val(long long x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = unit;
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = add(ret, tbl[k][i]);
        i = d.tbl[k][i];
      }
    return ret;
  }
};

DoublingFRel doubling_from_func(long long lim, int n, auto func) { return DoublingFRel(lim, n, func); }
DoublingFRel doubling_from_container(long long lim, int n, auto vec) {
  return DoublingFRel(lim, n, [&vec](int i) { return vec[i]; });
}
template<typename T, typename add_t = std::plus<T>>
auto doubling_cum_from_func(const DoublingFRel& d, auto mapping, T unit = T(), add_t add = plus<T>()) {
  return DoublingCum<T, decltype(add)>(d, mapping, unit, add);
}
template<typename T, typename add_t = std::plus<T>>
auto doubling_cum_from_container(const DoublingFRel& d, auto vec_mapping, T unit = T(), add_t add = plus<T>()) {
  return DoublingCum<T, decltype(add)>(d, [&vec_mapping](int i) { return vec_mapping[i]; }, unit, add);
}

// ---- end doubling.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll kmax = 1e12;

  ll N, Q, X; cin >> N >> Q >> X;
  // @InpVec(N, W) [vFd4OY7N]
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; W[i] = v; }
  // @End [vFd4OY7N]
  
  ll tot = accumulate(ALL(W), 0LL);
  vector<ll> vecF(N);
  vector<ll> vecC(N);
  ll x = X / tot;
  ll y = X % tot;
  ll j = 0;
  ll w = 0;
  ll cnt = x * N;
  REP(i, 0, N) {
    while (w < y) {
      w += W[j];
      j = (j + 1) % N;
      cnt++;
    }
    vecF[i] = j;
    vecC[i] = cnt;
    w -= W[i];
    cnt--;
  }
  auto d = doubling_from_container(kmax, N, vecF);

  REP(_q, 0, Q) {
    ll K; cin >> K;
    ll a = d.val(K - 1, 0);
    cout << vecC[a] << "\n";
  }

  return 0;
}

