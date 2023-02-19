#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Convex Hull Trick

  Answers to a sequence of the following type of queries.
  S is a set of linear functions f(x) = ax + b
  (1) Adds a line to S.
  (2) For given x_0, answers max({ f(x_0) | f \in S })     (or min)

  API

    template<typename T, typename D, bool obt_max> struct CHT;
    //  linear function f is of kind   f : ll -> T
    //  D is a field, containing T.
    //  If you need max, obt_max := true;  if you need min, obt_max := false
    
    member functions

      void insert(T a, T b);
      //  Adds "y = ax + b" to S
     
      T query(T x);
      //  Returns max( { f(x_0) | f \in S } )   or min(...) depending on obt_max

  Usage:

    CHT<ll, double, true> cht;
    cht.insert(1, 0);
    cht.insert(-1, 0);
    cout << cht.query(10) << endl;   // 10
    cout << cht.query(-5) << endl;   // 5

  Implementation
    - Maximum lines are kept in "set<Data> ds".
    - For d in ds, line "y = (d.a) x + (d.b)" is effective in interval [d.bnd, next(d).bnd]
    - The ordering of ds is mainly with field Data.a, but this is equivalent to the ordering with Data.bnd
    - For query(x0), we determine the segment that contains x0.  This is done by binary-searching ds using Data.bnd.
      For this purpose we use Data.eff: when the value is E_A_DUM, comparison uses Data.bnd rather tnan Data.a.
    - Minimum is calculated by calculating maximum for -f
 */


//////////////////////////////////////////////////////////////////////
// @@ !! BEGIN()  ---- cht.cc

template<typename T, typename D, bool obt_max>
struct CHT {
  enum {E_ORD, E_MAX, E_A_DUM};
  struct Data {
    T a;
    T b;
    D bnd;
    int eff; // E_ORD: (ordinary), E_MAX: (bnd is maximum), E_A_DUM: (a is dummy)
    Data(T a_ = T(), T b_ = T(), D bnd_ = D(), int eff_ = 0) : a(a_), b(b_), bnd(bnd_), eff(eff_) {}
    bool operator <(const Data& o) const {
      if (eff == 2 or o.eff == 2) return eff != 1 and (o.eff == 1 or bnd < o.bnd);
      else return a < o.a;
    }
    bool operator >(const Data& o) const { return o > *this; }
    bool operator <=(const Data& o) const { return not (*this > o); }
    bool operator >=(const Data& o) const { return not (*this < o); }
    friend ostream& operator <<(ostream& ostr, const Data& cht) {
      ostr << "[" << cht.a << ", " << cht.b << ", " << cht.bnd << ", " << cht.eff << "]";
      return ostr;
    }
  };
  set<Data> ds;
  // For example, if ds = {{a1, b1, d1, 0}, {a2, b2, d2, 0}, {a3, b3, dummy, 1}}, then there are three
  // lines li: y = ai x + bi.  l1 is max(min) on (-\infty, d1), l2 on (d1, d2), l3 on (d2, \infty).

  bool compare(D x, D y) { return x < y; };

  static pair<D, D> _intersection(T a, T b, T c, T d) {
    D x = - (D)(b - d) / (D)(a - c);
    D y = (D)(a * d - b * c) / (D)(a - c);
    return {x, y};
  };

  bool _effective(auto it, T a, T b) {
    if (it == ds.end()) return true;
    if (it->a == a) return compare((D)it->b, (D)b);
    if (it == ds.begin()) return true;
    auto it2 = prev(it);
    auto [p, q] = _intersection(it2->a, it2->b, it->a, it->b);
    return compare(q, a * p + b);
  }

  bool _it_move(auto& it, bool up) {
    if (up) {
      it++;
      return it != ds.end();
    }else {
      if (it == ds.begin()) return false;
      it--;
      return true;
    }
  }

  auto _refresh(auto it, T a, T b, bool up) {
    while (true) {
      auto it2 = it;
      if (not _it_move(it2, up)) break;
      auto [p, q] = _intersection(a, b, it2->a, it2->b);
      if (compare(q, it->a * p + it->b)) break;
      ds.erase(it);
      it = it2;
    }
    auto [p, q] = _intersection(a, b, it->a, it->b);
    return make_pair(it, p);
  }

  void insert(T a, T b) {
    if (not obt_max) { a = -a; b = -b; }

    auto it = ds.lower_bound(Data(a, b, D()));

    bool rc = _effective(it, a, b);
    if (not rc) return;
    if (it != ds.end() and it->a == a) {
      it = ds.erase(it);
    }

    if (it == ds.end()) {
      it = ds.emplace_hint(it, a, b, D(), E_MAX);
    } else {
      auto [it4, p] = _refresh(it, a, b, true);
      it = ds.emplace_hint(it4, a, b, p);
    }
    if (it != ds.begin()) {
      auto [it2, p] = _refresh(prev(it), a, b, false);
      auto [aa, bb, _1, _2] = *it2;
      ds.erase(it2);
      ds.emplace_hint(it, aa, bb, p);
    }
  }

  T query(T x) {
    auto it = ds.lower_bound(Data(T(), T(), (D)x, E_A_DUM));
    T ret = it->a * x + it->b;
    if (not obt_max) { ret = -ret; }
    return ret;
  }
};

// @@ !! END  ---- cht.cc


