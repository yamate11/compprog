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

// @@ !! LIM(intervalSet forall)

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

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto answer = [&](ll x, ll y) -> pll {
    cout << x + 1 << " " << y << endl;
    ll a, b; cin >> a >> b;
    return pll(a - 1, b);
  };

  ll N, L, R; cin >> N >> L >> R;
  if (L < R) {
    cout << "First" << endl;
    ll y = N % 2 == L % 2 ? L : L + 1;
    ll x = (N - y) / 2;
    ll a, b;
    tie(a, b) = answer(x, y);
    while (true) {
      if (b == 0) { return 0; }
      if (a < x) tie(a, b) = answer(x + y + a, b);
      else       tie(a, b) = answer(a - (x + y), b);
    }
  }else {
    vector<ll> tbl(N + 1, -1LL);
    auto gr = [&](auto rF, ll t) -> ll {
      auto& ret = tbl[t];
      if (ret < 0) {
        vector<bool> g;
        REP(i, 0, t - L + 1) {
          ll p = rF(rF, i);
          ll q = rF(rF, t - i - L);
          if ((p ^ q) >= SIZE(g)) g.resize((p ^ q) + 1);
          g[p ^ q] = true;
        }
        ret = EXFIND_D(i, 0, SIZE(g), not g[i], SIZE(g));
      }
      return ret;
    };
    auto realize = [&](ll k, ll g) -> ll {
      return EXFIND(i, 0, k - L + 1, (gr(gr, i) ^ gr(gr, k - i - L)) == g);
    };
    ll g = gr(gr, N);
    itv_set<ll> is(0);
    ll a, b;
    is.put(0, N, 1);
    if (g == 0) {
      cout << "Second" << endl;
      cin >> a >> b; a--;
    }else {
      cout << "First" << endl;
      ll i = realize(N, 0);
      is.put(i, i + L, 0);
      tie(a, b) = answer(i, L);
    }
    while (true) {
      if (b == 0) { return 0; }
      assert(b == L);
      auto [u, v] = is.get_itvl(a);
      ll gz = gr(gr, v - u);
      ll gx = gr(gr, a - u);
      ll gy = gr(gr, v - (a + L));
      ll gxyz = gx ^ gy ^ gz;
      is.put(a, a + L, 0);
      bool bbb = false;
      ll prev = -1;
      for (auto [p, s] : is.impl) {
        if (s == 1) prev = p;
        else if (prev >= 0) {
          ll gg = gr(gr, p - prev);
          ll gn = gg ^ gxyz;
          if (gn < gg) {
            ll len = realize(p - prev, gg ^ gxyz);
            is.put(prev + len, prev + len + L, 0);
            tie(a, b) = answer(prev + len, L);
            bbb = true;
            break;
          }
        }
      }
      assert(bbb);
    }
  }
  return 0;
}

