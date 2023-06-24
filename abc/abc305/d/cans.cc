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

// @@ !! LIM(intervalSet)

// ---- inserted library file intervalSet.cc

template<typename T>
struct itv_set_cell {
};

template<typename T>
struct itv_set {
  
  auto get_iter(ll x) {
    auto it = impl.upper_bound(x);
    return std::prev(it);
  }

  auto get_iter(ll x) const {
    auto it = impl.upper_bound(x);
    return std::prev(it);
  }

  auto divide(ll x) {
    auto it_nxt = impl.upper_bound(x);
    auto it = std::prev(it_nxt);
    if (it->first == x) return it;
    return impl.emplace_hint(it_nxt, x, it->second);
  }

  map<ll, T> impl;  // impl always has (LLONG_MIN, *) and (LLONG_MAX, *) as centinels.

  itv_set(const T& t = T()) {
    impl[LLONG_MIN] = t;
    impl[LLONG_MAX] = T();
  }

  void put(ll l, ll r, const T& t) {
    if (l >= r) return;
    if (l == LLONG_MIN) throw runtime_error("itv_set.put: l == LLONG_MIN");
    if (r == LLONG_MAX) throw runtime_error("itv_set.put: l == LLONG_MAX");
    auto it0 = divide(l);
    auto it1 = divide(r);
    it0->second = t;
    for (auto it = std::next(it0); it != it1; it = impl.erase(it));
    auto it2 = std::prev(it0);
    if (it0->second == it1->second) impl.erase(it1);
    if (it2->second == it0->second) impl.erase(it0);
  }

  void put(ll x, const T& t) { put(x, x + 1, t); }

  void put_at_end(ll x, const T& t) {
    auto it2 = std::prev(impl.end());
    auto it1 = std::prev(it2);
    if (it1->second != t) impl.emplace_hint(it2, x, t);
  }

  const T& get_val(ll x) const { return get_iter(x)->second; }

  pair<ll, ll> get_itvl(ll x) {
    auto it = impl.upper_bound(x);
    return {std::prev(it)->first, it->first};
  }

  pair<T, pair<ll, ll>> get(ll x) {
    auto it = impl.upper_bound(x);
    return {std::prev(it)->second, {std::prev(it)->first, it->first}};
  }

  T sum(ll l0, ll r0) {
    T ret = T();
    ll i = l0;
    while (true) {
      const auto& [t, lr] = get(i);
      const auto& [l, r] = lr;
      ret += (min(r, r0) - i) * t;
      if (r0 <= r) return ret;
      i = r;
    }
  }

};

template<typename x_t, typename y_t, typename res_t, typename f_t>
itv_set<res_t> itv_apply(f_t f, const itv_set<x_t>& x, const itv_set<y_t>& y) {
  auto itx = x.impl.begin();
  auto ity = y.impl.begin();
  itv_set<res_t> ret(f(itx->second, ity->second));
  auto itcc = ret.impl.begin();
  auto itce = std::next(itcc);
  while (true) {
    ll t;
    tie(t, itx, ity) = [&]() -> tuple<ll, decltype(itx), decltype(ity)> {
      auto nitx = std::next(itx);
      auto nity = std::next(ity);
      if      (nitx->first <  nity->first) return {nitx->first, nitx,  ity};
      else if (nitx->first >  nity->first) return {nity->first,  itx, nity};
      else if (nitx->first < LLONG_MAX)    return {nitx->first, nitx, nity};
      else                                 return {-1,          nitx, nity};
    }();
    if (t == -1) break;
    res_t ncur = f(itx->second, ity->second);
    if (ncur != itcc->second) itcc = ret.impl.emplace_hint(itce, t, move(ncur));
  }
  return ret;
}

// ---- end intervalSet.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [Cvoxi9tr]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Cvoxi9tr]
  ll Q; cin >> Q;
  // @InpMVec(Q, (L, R)) [6vSvSGUi]
  auto L = vector(Q, ll());
  auto R = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [6vSvSGUi]
  
  enum KIND { START, END, ASK };
  using ev_t = pair<ll, KIND>;
  vector<ev_t> ev;
  REP(i, 0, N) {
    if (i % 2 == 0) ev.emplace_back(A[i], END);
    else ev.emplace_back(A[i], START);
  }
  REP(q, 0, Q) {
    ev.emplace_back(L[q], ASK);
    ev.emplace_back(R[q], ASK);
  }
  sort(ALL(ev));
  ll prev_start = 0;
  ll acc = 0;
  map<ll, ll> mp;
  for (auto [t, kind] : ev) {
    if (kind == START) {
      prev_start = t;
    }else if (kind == END) {
      acc += t - prev_start;
      prev_start = -1;
    }else if (kind == ASK) {
      ll x;
      if (prev_start < 0) x = acc;
      else x = acc + t - prev_start;
      mp[t] = x;
    }else assert(0);
  }
  REP(q, 0, Q) {
    cout << mp[R[q]] - mp[L[q]] << "\n";
  }


  /*
  itv_set<ll> is(-1LL);
  REP(i, 0, N / 2) {
    is.put(A[2*i], A[2*i + 1], 0);
    is.put(A[2*i + 1], A[2*i + 2], 1);
  }

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r;
    cout << is.sum(l, r) << "\n";
  }
  */
  
  

  return 0;
}

