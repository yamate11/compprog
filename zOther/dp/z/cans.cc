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

// @@ !! LIM(cht)

// ---- inserted library file cht.cc

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, C; cin >> N >> C;
  // @InpVec(N, H) [lg02IVuY]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [lg02IVuY]
  CHT<ll, double, false> cht;
  ll cur = 0;
  REP(i, 0, N - 1) {
    cht.insert(-2 * H[i], cur + H[i] * H[i]);
    cur = cht.query(H[i + 1]) + H[i + 1] * H[i + 1] + C;
  }
  cout << cur << endl;

  return 0;
}

