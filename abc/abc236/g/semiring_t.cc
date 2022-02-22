#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))


/*
  matrix<T> のような，semiring T の上に構築するクラスは，
  以下のようなものがあると信じて書きたい．
     T static T::zero();
     T static T::one();
     T& operator +=(const T&);
     T& operator *=(const T&);
     T operator +(const T&) const;
     T operator *(const T&) const;

  でも，これだと，たとえば，ll::zero(); のようなものを要求することになって，無理．

  となると，
     Zero<SR> というクラスをつくって，
     Zero<SR> z{};
     として，z() が 単位元を返せば良いのではないか．

  しかし，そうなると，いちいち
     template<>
     class Zero<ll> {...} と定義していかなければならなくて面倒だ．

  Assoc Struct を作れば良いか?

  演算セットごとに

  struct SRord_ll : SRbase<ll> {
    ll zero() { return 0LL; }
    ll one() { return 1LL; }
    void subst_plus(ll& v, const ll w) { v += w; }
    void subst_mult(ll& v, const ll w) { v *= w; }
  };

  を作っておく．matrix では，matrix<SRop_ll> のように指定する．

*/


struct SRord_ll {
  using ult = ll;
  ll zero() { return 0LL; }
  ll one() { return 1LL; }
  void subst_plus(ll& v, const ll& w) { v += w; }
  void subst_mult(ll& v, const ll& w) { v *= w; }
};

template<typename OP>
struct SR {
  using ult_t = typename OP::ult;
  ult_t zero() { return OP().zero(); }
  ult_t one() { return OP().one(); }
  void subst_plus(ult& v, const ult& w) { return OP().subst_plus(v, w); }
  void subst_mult(ult& v, const ult& w) { return OP().subst_mult(v, w); }
  ult plus(const ult& v, const ult& w) { ult z(v); subst_plus(z, w); return z; }
  ult mult(const ult& v, const ult& w) { ult z(v); subst_mult(z, w); return z; }
}


struct SRop_ll {
  using ult = ll;   // under-lying type
  ult zero() { return 0LL; }
  ult one() { return 1LL; }
  void subst_plus(ult& v, const ult w) { v += w; }
  void subst_mult(ult& v, const ult w) { v *= w; }
};

struct SRop_maxmin {
  using ult = ll;
  ult zero() { return LLONG_MIN; }
  ult one() { return LLONG_MAX; }
  void subst_plus(ult& v, const ult w) { if (v < w) v = w; }
  void subst_mult(ult& v, const ult w) { if (v > w) v = w; }
};

template<typename SRop>
struct SemiRingRep {
  using ult_t = typename SRop::ult;
  ult_t v;
  SemiRingRep() : v(SRop().zero()) {}
  SemiRingRep(const ult_t& v_) : v(v_) {}
  SemiRingRep(const SemiRingRep& o) : v(o.v) {}
  SemiRingRep& operator =(const ult_t& v_) { v = v_; }
  SemiRingRep& operator =(const SemiRingRep& o) : { v = o.v; }
  SemiRingRep& operator +=(const SemiRingRep& o) { subst_plus(v, o.v); return *this; }
  SemiRingRep& operator *=(const SemiRingRep& 
};

  
