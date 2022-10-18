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

// @@ !! LIM()


struct LLMin {
  ll _v;
  LLMin() : _v(LLONG_MAX) {}
  LLMin(ll x) : _v(x) {}
  LLMin operator +(LLMin o) { return LLMin(min(_v, o._v)); }
};

struct MyDat {
  pll _v;
  MyDat() : _v(LLONG_MAX, LLONG_MIN) {}
  MyDat(const pll& x) : _v(x) {}
  MyDat operator +(MyDat o) { return MyDat(pll(min(_v.first, o._v.first), max(_v.second, o._v.second))); }
};


// むしろ，

template<typename DAT, typename oplus_, typename appl_t>
struct SegTree {
  vector<DAT> vec;
  oplus_t oplus;
  DAT unit;
  appl_t appl;
  SegTree(int sz, oplus_t oplus_, DAT, unit_, appl_t, appl_)
    : vec(sz), oplus(oplus_), unit(unit_), appl(appl_) {}

};
  



template<typename DAT>
struct Zsubst {
  optional<DAT> _v;
  Zsubst() : _v() {}
  Zsubst(DAT t) : _v(t) {}
  Zsubst operator *(const Zsubst& f) { return _v ? *this : f; }
  DAT operator ()(const DAT& x) { return _v ? *_v : x; }
};


int main() {

  pll myUnit(LLONG_MAX, LLONG_MIN);
  auto myOplus = [&](pll x, pll y) -> pll {
    const auto& [a, b] = x;
    const auto& [c, d] = y;
    return pll(min(a, c), max(b, d));
  };
  SegDAT<pll> myDAT(myUnit, myOplus);
  
  auto st = make_lazy_seg_tree(N, myDAT, myOP);

  auto st1 = make_lazy_seg_tree(N, STllmin, STsubst);


  using DAT = LLMin;
  using OP = Zsubst<DAT>;
  DAT x(2), y(5);
  OP f(3), g;
  cout << (x + y)._v << endl;
  cout << (f(x) + g(y))._v << endl;


  return 0;
};
