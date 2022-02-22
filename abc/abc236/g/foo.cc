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

// @@ !! LIM(f:perfmeas)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

struct Hmin {
  using base_t = ll;
  constexpr ll unit() { return LLONG_MAX; }
  void subst_plus(ll& v, const ll w) {
    if (v > w) v = w;
  }
};  

struct Hmax {
  using base_t = ll;
  constexpr ll unit() { return LLONG_MIN; }
  void subst_plus(ll& v, const ll w) {
    if (v < w) v = w;
  }
};  

template<typename Helper>
using base_tt = typename Helper::base_t;


template<typename Helper>
struct Ztmp {
  base_tt<Helper> v;
  Ztmp() : v(Helper().unit()) {}
  Ztmp(ll v_) : v(v_) {}
  Ztmp(const Ztmp& o) : v(o.v) {}
  Ztmp& operator =(const Ztmp& o) { v = o.v; return *this; }
  Ztmp& operator =(ll v_) { v = v_; return *this; }
  Ztmp& operator +=(const Ztmp& o) {
    Helper().subst_plus(v, o.v);
    return *this;
  }
  Ztmp operator +(const Ztmp& o) const {
    Ztmp ret(*this);
    ret += o;
    return ret;
  }
  bool operator ==(const Ztmp& o) const { return v == o.v; }
  bool operator !=(const Ztmp& o) const { return v != o.v; }
  operator ll() const { return v; }
  friend istream& operator>>(istream& is, Ztmp& z) { return is >> z.v; }
  friend ostream& operator<<(ostream& os, const Ztmp& z) { return os << z.v; }
  static ll unit() { return Helper().unit(); };
};

using Zmin = Ztmp<Hmin>;
using Zmax = Ztmp<Hmax>;

/*
struct Zmin {
  ll v;
  Zmin() : v(Hmin().unit()) {}
  Zmin(ll v_) : v(v_) {}
  Zmin(const Zmin& o) : v(o.v) {}
  Zmin& operator =(const Zmin& o) { v = o.v; return *this; }
  Zmin& operator =(ll v_) { v = v_; return *this; }
  Zmin& operator +=(const Zmin& o) {
    Hmin().subst_plus(v, o.v);
    return *this;
  }
  Zmin operator +(const Zmin& o) const {
    Zmin ret(*this);
    ret += o;
    return ret;
  }
  bool operator ==(const Zmin& o) const { return v == o.v; }
  bool operator !=(const Zmin& o) const { return v != o.v; }
  operator ll() const { return v; }
  friend istream& operator>>(istream& is, Zmin& z) { return is >> z.v; }
  friend ostream& operator<<(ostream& os, const Zmin& z) { return os << z.v; }
};

struct Zmax {
  ll v;
  Zmax() : v(LLONG_MIN) {}
  Zmax(ll v_) : v(v_) {}
  Zmax(const Zmax& o) : v(o.v) {}
  Zmax& operator =(const Zmax& o) { v = o.v; return *this; }
  Zmax& operator =(ll v_) { v = v_; return *this; }
  Zmax& operator +=(const Zmax& o) {
    if (v < o.v) v = o.v;
    return *this;
  }
  Zmax operator +(const Zmax& o) const {
    Zmax ret(*this);
    ret += o;
    return ret;
  }
  bool operator ==(const Zmax& o) const { return v == o.v; }
  bool operator !=(const Zmax& o) const { return v != o.v; }
  operator ll() const { return v; }
  friend istream& operator>>(istream& is, Zmax& z) { return is >> z.v; }
  friend ostream& operator<<(ostream& os, const Zmax& z) { return os << z.v; }
};
*/

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll inp = atoi(argv[1]);
  double t1 = get_time_sec();
  if (inp == 1) {
    ll n; cin >> n;
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      ll x; cin >> x;
      ans = min(ans, x);
    }
    cout << ans << endl;
  }else if (inp == 2) {
    ll n; cin >> n;
    Zmin ans;
    for (int i = 0; i < n; i++) {
      Zmin z; cin >> z;
      ans += z;
    }
    cout << ans << endl;
  }
  double t2 = get_time_sec();
  cout << "elaplsed: " << t2 - t1 << endl;

  cout << Zmin::unit() << endl;

  /*
  Zmin z1(5), z2(10);
  cout << z1 + z2 << endl;
  Zmax w1(20), w2(30);
  cout << w1 + w2 << endl;
  ll t = 5;
  cout << sizeof(z1) << " " << sizeof(t) << endl;
  */

  return 0;
}

