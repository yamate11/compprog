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

// @@ !! LIM(forall vicinity f:updMaxMin)

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

// ---- inserted library file vicinity.cc

template<typename Cont>
struct Vicinity {
  using Key = Cont::key_type;
  Cont& cont;
  Vicinity(Cont& cont_) : cont(cont_) {}
  Cont::iterator _le_lt(const Key& x, bool with_eq) {
    if (with_eq) {
      auto it_eq = cont.find(x);
      if (it_eq != cont.end()) return it_eq;
    }
    auto it = cont.lower_bound(x);
    if (it == cont.begin()) return cont.end();
    return std::prev(it);
  }
  Cont::iterator le(const Key& x) { return _le_lt(x, true); }
  Cont::iterator lt(const Key& x) { return _le_lt(x, false); }
  Cont::iterator ge(const Key& x) { return cont.lower_bound(x); }
  Cont::iterator gt(const Key& x) { return cont.upper_bound(x); }

};

// ---- end vicinity.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, WW; cin >> N >> WW;
  // @InpMVec(N, (V, W)) [WlIqDWCe]
  auto V = vector(N, ll());
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; V[i] = v1;
    ll v2; cin >> v2; W[i] = v2;
  }
  // @End [WlIqDWCe]



  auto solve1 = [&]() -> ll {
    auto f = [&](ll a, ll b) {
      map<ll, ll> mp;
      mp[0] = 0;
      ll len = b - a;
      REP(x, 0, 1LL << len) {
        ll Vsum = 0;
        ll Wsum = 0;
        REP(i, 0, len) {
          if (x >> i & 1) {
            Vsum += V[a + i];
            Wsum += W[a + i];
          }
        }
        mp[Wsum] = max(mp[Wsum], Vsum);
      }
      map<ll, ll> ret;
      ll cur = -1;
      for (auto [w, v] : mp) {
        if (cur < v) {
          ret[w] = v;
          cur = v;
        }
      }
      return ret;
    };
    ll M1 = N / 2;
    auto vec1 = f(0, M1);
    auto vec2 = f(M1, N);
    ll ans = 0;
    Vicinity vc(vec2);
    for (auto [w, v] : vec1) {
      if (w > WW) continue;
      auto it = vc.le(WW - w);
      ans = max(ans, v + it->second);
    }
    return ans;
  };

  auto solve2 = [&]() -> ll {
    ll lim = 200 * 1000;
    vector tbl(lim + 1, 0LL);
    REP(i, 0, N) {
      REPrev(w, lim - W[i], 0) {
        updMax(tbl[w + W[i]], tbl[w] + V[i]);
      }
    }
    ll ans = 0;
    REP(w, 0, WW + 1) {
      ans = max(ans, tbl[w]);
    }
    return ans;
  };

  auto solve3 = [&]() -> ll {
    ll big = 1e18;
    ll lim = 200 * 1000;
    vector tbl(lim + 1, big);
    tbl[0] = 0;
    REP(i, 0, N) {
      REPrev(v, lim - V[i], 0) {
        updMin(tbl[v + V[i]], tbl[v] + W[i]);
      }
    }
    REPrev(v, lim, 0) {
      if (tbl[v] <= WW) {
        return v;
      }
    }
    assert(0);
  };

  ll ans = -1;
  if (N <= 30) ans = solve1();
  else if (FORALL(i, 0, N, W[i] <= 1000)) ans = solve2();
  else ans = solve3();
  cout << ans << endl;

  return 0;
}

