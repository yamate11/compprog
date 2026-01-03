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

template<typename T = void, typename Add = void>
struct Doubling {
  static constexpr bool HAS_T = not is_void_v<T>;
  using Node = conditional_t<HAS_T, pair<int, T>, int>;

  int n{};
  vector<vector<Node>> tbl;
  [[no_unique_address]] conditional_t<HAS_T, T, monostate> unit{};
  [[no_unique_address]] conditional_t<HAS_T, Add, monostate> add{};

  int& nd_int(Node& nd) { if constexpr (HAS_T) return nd.first; else return nd; }

  void prepare_tbl(u64 lim, const auto& nxt) {
    int K = 64 - countl_zero(lim);
    tbl.resize(K, vector<Node>(n));
    for (int i = 0; i < n; i++) nd_int(tbl[0][i]) = nxt[i];
  }

  void fill_tbl(u64 lim) {
    for (int k = 0; k + 1 < ssize(tbl); k++) {
      for (int i = 0; i < n; i++) {
        nd_int(tbl[k + 1][i]) = nd_int(tbl[k][nd_int(tbl[k][i])]);
        if constexpr (HAS_T) tbl[k + 1][i].second = add(tbl[k][i].second, tbl[k][tbl[k][i].first].second);
      }
    }
  }

  Doubling() {}

  Doubling(ll lim, int n_, const auto& nxt) requires (not HAS_T) : n(n_) {
    prepare_tbl(lim, nxt);
    fill_tbl(lim);
  }

  template<typename U = T, typename A = Add> requires (HAS_T)
  Doubling(ll lim, int n_, const auto& nxt, const auto& mapping, U unit_, A add_)
    : n(n_), unit(unit_), add(add_) {
    prepare_tbl(lim, nxt);
    for (int i = 0; i < n; i++) tbl[0][i].second = mapping[i];
    fill_tbl(lim);
  }

  Node val(ll x, int i) {
    Node ret;
    nd_int(ret) = i;
    if constexpr (HAS_T) ret.second = unit;
    for (int k = 0; x > 0; x >>= 1, k++) {
      if (x & 1) {
        Node cur = tbl[k][nd_int(ret)];
        nd_int(ret) = nd_int(cur);
        if constexpr (HAS_T) ret.second = add(ret.second, cur.second);
      }
    }
    return ret;
  }

};

template<typename T, typename Add>
auto make_doubling_with_monoid_unit_add(ll lim, int n, const auto& nxt, const auto& mapping, T unit, Add add) {
  return Doubling<T, decltype(add)>(lim, n, nxt, mapping, unit, add);
}
template<typename T>
auto make_doubling_with_monoid(ll lim, int n, const auto& nxt, const auto& mapping) {
  return make_doubling_with_monoid_unit_add(lim, n, nxt, mapping, T(), plus<T>());
}



/*
struct DoublingFRel { // from functional relation
  int n;
  vector<vector<int>> tbl;

  void _init(ll lim, auto frel) {
    int K = 64 - countl_zero((u64)lim);
    tbl.resize(K, vector<int>(n));
    for (int i = 0; i < n; i++) tbl[0][i] = frel(i);
    for (int k = 0; k + 1 < K; k++) for (int i = 0; i < n; i++) tbl[k + 1][i] = tbl[k][tbl[k][i]];
  }

  DoublingFRel(ll lim, int n_, auto frel) : n(n_) { _init(lim, frel); }
  static DoublingFRel from_container(ll lim, int n, auto vec) {
    return DoublingFRel(lim, n, [&](int i) { return vec[i]; });
  }

  int val(ll x, int i) { // Calculates frel^{(x)}(i).  Should be x <= lim.
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

  T val(ll x, int i) { // the monoid sum of x objs from i.  i.e. from i to i + x - 1.
    T ret = unit;
    for (int k = 0; x > 0; x >>= 1, k++) if (x & 1) {
        ret = add(ret, tbl[k][i]);
        i = d.tbl[k][i];
      }
    return ret;
  }
};

DoublingFRel doubling_from_func(ll lim, int n, auto func) { return DoublingFRel(lim, n, func); }
DoublingFRel doubling_from_container(ll lim, int n, auto vec) {
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
*/

// ---- end doubling.cc

// @@ !! LIM -- end mark --

int main() {
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N);
  REP(i, 0, N) { cin >> A[i]; A[i]--; }
  vector<ll> B(N);
  REP(i, 0, N) B[i] = i + 1;
  auto dobj = make_doubling_with_monoid<ll>((ll)1e9, N, A, B);
  REP(_q, 0, Q) {
    ll t, b; cin >> t >> b; b--;
    cout << dobj.val(t, b).second << "\n";
  }
  return 0;
}

