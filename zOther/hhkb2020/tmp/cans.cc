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
    if (l >= r) throw runtime_error("itv_set.put: l >= r");
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

  pair<ll, pair<ll, ll>> get(ll x) {
    auto it = impl.upper_bound(x);
    return {std::prev(it)->second, {std::prev(it)->first, it->first}};
  }

  template<typename F>
  friend itv_set itv_apply(F f, itv_set x, itv_set y) {
    auto itx = x.impl.begin();
    auto ity = y.impl.begin();
    itv_set ret(f(itx->second, ity->second));
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
      T ncur = f(itx->second, ity->second);
      if (ncur != itcc->second) itcc = ret.impl.emplace_hint(itce, t, move(ncur));
    }
    return ret;
  }
};

// ---- end intervalSet.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, Q; cin >> N >> M >> Q;
  enum ev_kind {ASK, SET};
  using ev_t = tuple<ll, ev_kind, ll, ll, ll>;
  vector<ev_t> ev;
  REP(i, 0, M) {
    ll d, a, b; cin >> d >> a >> b;
    ev.emplace_back(d, SET, a, b, 0);
  }
  REP(i, 0, Q) {
    ll e, s, t; cin >> e >> s >> t;
    ev.emplace_back(e, ASK, s, t, i);
  }
  sort(ALL(ev));
  vector<bool> ans(Q);
  itv_set<ll> is;
  for (auto [d, kd, a, b, q] : ev) {
    if (kd == SET) {
      is.put(a, b, 1);
    }else if (kd == ASK) {
      if (a >= b) {
        ans[q] = true;
      }else {
        auto [v, xy] = is.get(a);
        ans[q] = v == 1 and b <= xy.second;
      }
    }else assert(0);
  }
  REPOUT(i, 0, Q, ans[i] ? "Yes" : "No", "\n");
  return 0;
}

