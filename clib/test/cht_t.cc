#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cht)

// ---- inserted library file cht.cc
#line 49 "/home/y-tanabe/proj/compprog/clib/cht.cc"

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

// ---- end cht.cc

// @@ !! LIM -- end mark --
#line 7 "cht_skel.cc"

template<typename T, typename D, bool obt_max>
struct NaiveCHT {
  vector<T> vecA;
  vector<T> vecB;
  
  bool compare(D x, D y) {
    if constexpr (obt_max) return less<D>()(x, y);
    else                   return greater<D>()(x, y);
  }

  void insert(T a, T b) {
    vecA.push_back(a);
    vecB.push_back(b);
  }

  T query(T x) {
    T ans = vecA[0] * x + vecB[0];
    for (size_t i = 1; i < vecA.size(); i++) {
      T v = vecA[i] * x + vecB[i];
      if (compare(ans, v)) ans = v;
    }
    return ans;
  }
};
  

random_device rd;
mt19937_64 rng(rd());
ll randrange(ll i, ll j) {
  uniform_int_distribution<ll> dist(i, j - 1);
  return dist(rng);
}
  
template<bool dir>
void test_rnd() {
  const ll rep_out = 500;
  const ll rep_in = 500;
  const double ratio = 0.4;
  for (size_t i = 0; i < rep_out; i++) {
    CHT<ll, double, dir> cht;
    NaiveCHT<ll, double, dir> ncht;
    const ll range_min = randrange(-100, 101);
    const ll range_size = randrange(1, 100);
    auto g = [&]() -> ll { return randrange(range_min, range_min + range_size); };
    // DLOG("---------------");
    for (size_t j = 0; j < rep_in; j++) {
      if (j == 0 or randrange(0, 100000) < ratio * 100000) {
        ll a = g(), b = g();
        cht.insert(a, b);
        ncht.insert(a, b);
        // DLOGKL("** insert **", a, b);
      }else {
        ll x = g();
        if (cht.query(x) != ncht.query(x)) {
          cerr << "****** different ******  " << x << " " <<  cht.query(x) << " " <<  ncht.query(x) << endl;
          assert(0);
        }
      }
    }
  }
}

void test() {

  {
    CHT<ll, double, true> cht;
    cht.insert(2, 0);
    cht.insert(-2, 60);
    cht.insert(0, 40);
    assert(cht.query(3) == 54);
    assert(cht.query(15) == 40);
    assert(cht.query(21) == 42);

    CHT<ll, double, false> chtMin;
    chtMin.insert(2, 0);
    chtMin.insert(-2, 60);
    chtMin.insert(0, 40);
    assert(chtMin.query(3) == 6);
    assert(chtMin.query(15) == 30);
    assert(chtMin.query(21) == 18);
  }

}

void test2() {
  CHT<int, double, true> cht;
  cht.insert(0, 3);
  assert(cht.query(0) == 3);
  cht.insert(-1, 4);
  assert(cht.query(0) == 4);
  assert(cht.query(10) == 3);
  assert(cht.query(-10) == 14);
  cht.insert(1, 2);
  assert(cht.query(0) == 4);
  assert(cht.query(10) == 12);
  assert(cht.query(-10) == 14);
}


int main() {

  test();
  test2();
  test_rnd<true>();
  test_rnd<false>();

  return 0;
}
