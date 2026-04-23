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

// @@ !! LIM(ipoint unordered_map)

// ---- inserted library file ipoint.cc

struct IPoint {
  ll x;
  ll y;
  IPoint(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

  IPoint rotate(int r = 1) const {
    ll rd = r % 4;
    ll rr = r >= 0 ? rd : rd == 0 ? 0 : rd + 4;
    if      (rr == 0) return IPoint( x,  y);
    else if (rr == 1) return IPoint(-y,  x);
    else if (rr == 2) return IPoint(-x, -y);
    else if (rr == 3) return IPoint( y, -x);
    assert(0);
  }

  IPoint mirror_x() const { return IPoint(x, -y); }
  IPoint mirror_y() const { return IPoint(-x, y); }

  auto operator<=>(const IPoint&) const = default;   // This generates ==, !=, <, >, <=, >=.

  IPoint& operator +=(const IPoint& o) {
    x += o.x;
    y += o.y;
    return *this;
  }

  IPoint& operator -=(const IPoint& o) {
    x -= o.x;
    y -= o.y;
    return *this;
  }

  IPoint& operator *=(ll k) {
    x *= k;
    y *= k;
    return *this;
  }

  IPoint operator +(const IPoint& o) const { return IPoint(x, y) += o; }
  IPoint operator -(const IPoint& o) const { return IPoint(x, y) -= o; }
  IPoint operator *(ll k) const { return IPoint(x, y) *= k; }
  IPoint operator -() const { return IPoint(-x, -y); }

  bool parallel(const IPoint o) const { return x * o.y == y * o.x; }

  // For "argument sort".  The origin is treated as the maximum.
  static bool lt_arg(const IPoint& p1, const IPoint& p2) {
    bool b1 = p1.y > 0 or (p1.y == 0 and p1.x > 0);
    bool b2 = p2.y > 0 or (p2.y == 0 and p2.x > 0);
    if (b1 != b2) return b1;
    else return p1.x * p2.y > p1.y * p2.x;
  }

};
    
IPoint operator *(ll k, const IPoint& p) { return p * k; }
istream& operator >>(istream& is, IPoint& p) {
  ll x_, y_; is >> x_ >> y_;
  p.x = x_;
  p.y = y_;
  return is;
}
ostream& operator <<(ostream& os, const IPoint& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

#if !defined(__TEMPLATE_SAFE_CUSTOM_HASH__)
#define __TEMPLATE_SAFE_CUSTOM_HASH__
template <typename T, typename Enable = void>
struct safe_custom_hash;
#endif

template<>
struct safe_custom_hash<IPoint, void> {
  std::size_t operator()(const IPoint& p) const {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
    static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
    return a * (uint64_t)p.x + b * (uint64_t)p.y;
  }
};

namespace std {
  template<>
  struct hash<IPoint> {
    std::size_t operator()(const IPoint& p) const { return safe_custom_hash<IPoint, void>()(p); }
  };
}


// ---- end ipoint.cc

// ---- inserted library file unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#if !defined(__TEMPLATE_SAFE_CUSTOM_HASH__)
#define __TEMPLATE_SAFE_CUSTOM_HASH__
template <typename T, typename Enable = void>
struct safe_custom_hash;
#endif

// For integer types (int, ll, u64, unsigned, ....)
template <typename T>
struct safe_custom_hash<T, typename enable_if<is_integral<T>::value>::type> {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

// For string
template <>
struct safe_custom_hash<string, void> {
  static uint64_t mix(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }

  size_t operator()(const string& s) const {
    static const uint64_t seed = chrono::steady_clock::now().time_since_epoch().count();
    uint64_t h = seed ^ 0x9e3779b97f4a7c15ULL;
    const unsigned char* p = (const unsigned char*)s.data();
    size_t n = s.size();
    while (n >= 8) {
      uint64_t v;
      memcpy(&v, p, 8);
      h = mix(h ^ v);
      p += 8; n -= 8;
    }
    uint64_t tail = 0;
    for (size_t i = 0; i < n; ++i) tail |= uint64_t(p[i]) << (8*i);
    h = mix(h ^ tail);
    return (size_t)h;
  }
};

// For pair
template <typename T1, typename T2>
struct safe_custom_hash<pair<T1, T2>, void> {
  size_t operator()(const pair<T1, T2>& x) const {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
    static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
    return a * safe_custom_hash<T1>{}(x.first) + b * safe_custom_hash<T2>{}(x.second);
  }
};

template <typename T_key, typename T_value, bool useGP = false>
using safe_umap = conditional_t<useGP, gp_hash_table<T_key, T_value, safe_custom_hash<T_key>>,
                                unordered_map<T_key, T_value, safe_custom_hash<T_key>>>;
template <typename T_key, bool useGP = false>
using safe_uset = conditional_t<useGP, gp_hash_table<T_key, null_type, safe_custom_hash<T_key>>,
                                unordered_set<T_key, safe_custom_hash<T_key>>>;
template <typename T_key>
using safe_umultiset = unordered_multiset<T_key, safe_custom_hash<T_key>>;


// ---- end unordered_map.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  IPoint S; cin >> S;
  // @InpVec(N, XY, type=IPoint) [FPMuGRLm]
  auto XY = vector(N, IPoint());
  for (int i = 0; i < N; i++) { IPoint v; cin >> v; XY[i] = v; }
  // @End [FPMuGRLm]
  
  safe_umap<ll, set<ll>> mpX;
  safe_umap<ll, set<ll>> mpY;
  REP(i, 0, N) {
    mpX[XY[i].x].insert(XY[i].y);
    mpY[XY[i].y].insert(XY[i].x);
  }
  safe_umap<char, IPoint> dir{{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};
  
  ll ans = 0;
  IPoint P = S;
  REP(_i, 0, M) {
    char d; cin >> d;
    ll len; cin >> len;
    IPoint Q = P + dir[d] * len;
    if (dir[d].y == 0) {
      ll a = P.x;
      ll b = Q.x;
      if (a > b) swap(a, b);
      auto& ss = mpY[P.y];
      auto it0 = ss.lower_bound(a);
      auto it1 = ss.lower_bound(b + 1);
      auto it = it0;
      while (it != it1) {
        mpX[*it].erase(P.y);
        it = ss.erase(it);
        ans++;
      }
    }else {
      ll a = P.y;
      ll b = Q.y;
      if (a > b) swap(a, b);
      auto& ss = mpX[P.x];
      auto it0 = ss.lower_bound(a);
      auto it1 = ss.lower_bound(b + 1);
      auto it = it0;
      while (it != it1) {
        mpY[*it].erase(P.x);
        it = ss.erase(it);
        ans++;
      }
    }
    P = Q;
  }
  cout << P.x << " " << P.y << " " << ans << endl;


  return 0;
}

