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

// @@ !! LIM(perm smallVec unordered_map)

// ---- inserted library file perm.cc

template <bool dup, typename T>
struct IntPermBase {
  int n;
  int r;
  vector<int> vec;
  bool started;
  vector<T> mapping;

  bool start_check() {
    if constexpr (dup) { if (not ((1 <= n and 0 <= r) or (n == 0 and r == 0))) return false; }
    else { if (not (0 <= n and 0 <= r and r <= n)) return false; }
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  IntPermBase(int n_, int r_) : n(n_), r(r_), started(false) {
    if (n >= 0) {
      mapping = vector<T>(n);
      for (int i = 0; i < n; i++) {
        if constexpr (is_integral<T>::value) mapping[i] = (T)i;
        else mapping[i] = T();
      }
    }
  }
  IntPermBase(int n_, int r_, vector<T> mp) : n(n_), r(r_), started(false), mapping(move(mp)) {
    if (ssize(mapping) != n) throw runtime_error("IntPermBase: incorrect mapping length");
  }

  T at(int i) const { return mapping[vec[i]]; }

  T operator[](int i) const { return at(i); }

  void set_mapping(auto f) {
    for (int i = 0; i < n; i++) mapping[i] = f(i);
  }

  vector<T> vec_view() const {
    vector<T> res;
    for (int i = 0; i < r; i++) res.push_back(mapping[vec[i]]);
    return res;
  }
};

template<typename T = int>
struct IntPerm : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started;

  vector<vector<int>> cands;
  vector<int> cidx;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    cands.resize(r);
    cidx.resize(r);
    for (int i = 0; i < r; i++) {
      for (int j = n - 1; j >= i; j--) cands[i].push_back(j);
      cidx[i] = n - i - 1;
    }
    return true;
  }

  bool finish() {
    cands.resize(0);
    cidx.resize(0);
    return IntPermBase<false, T>::finish();
  }

  IntPerm(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntPerm(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and cidx[i] == 0; i--);
    if (i < 0) return finish();
    vec[i] = cands[i][--cidx[i]];
    for (int j = i + 1; j < r; j++) {
      if (j == i + 1) {
        cands[j].resize(0);
        for (int k = 0; k < (int)cands[i].size(); k++) {
          if (k == cidx[i]) continue;
          cands[j].push_back(cands[i][k]);
        }
      }else {
        cands[j] = cands[j - 1];
        cands[j].pop_back();
      }
      cidx[j] = n - j - 1;
      vec[j] = cands[j][cidx[j]];
    }
    return true;
  }
};

template<typename T = int>
struct IntComb : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntComb(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - r + i; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[j - 1] + 1;
    return true;
  }
};

template<typename T = int>
struct IntDupPerm : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupPerm(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupPerm(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

template<typename T = int>
struct IntDupComb : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupComb(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupComb(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - 1; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[i];
    return true;
  }
};

template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  int r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  int at(int i) const { return vec[i]; }

  const vector<INT>& vec_view() const { return vec; }

  bool start_check() {
    for (int i = 0; i < r; i++) if (lim[i] == 0) return false;
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < lim[i]) return true;
    return finish();
  }
};

template<typename INT>
struct IntPartition {
  INT n;
  vector<INT> vec;
  bool started = false;
  IntPartition(INT n_) : n(n_) {}
  
  bool get() {
    if (not started) {
      started = true;
      vec = vector<INT>(n, 1);
      return true;
    }else if (ssize(vec) == 1) {
      started = false;
      return false;
    }else {
      ll b = vec.back(); vec.pop_back();
      ll a = vec.back(); vec.pop_back();
      ll c = a + b;
      ll a1 = a + 1;
      while (c - a1 >= a1) {
        vec.push_back(a1);
        c -= a1;
      }
      vec.push_back(c);
      return true;
    }
  }

  INT at(int i) const { return vec[i]; }
  const vector<INT>& vec_view() const { return vec; }
};

// ---- end perm.cc

// ---- inserted library file unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
*/

template <typename T, typename Enable = void>
struct safe_custom_hash;

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

template <typename T_key, typename T_value>
using safe_umap = unordered_map<T_key, T_value, safe_custom_hash<T_key>>;

template <typename T_key>
using safe_uset = unordered_set<T_key, safe_custom_hash<T_key>>;

template <typename T_key>
using safe_umultiset = unordered_multiset<T_key, safe_custom_hash<T_key>>;


// ---- end unordered_map.cc

// ---- inserted library file smallVec.cc

template<int bits>
struct small_vector_u64 {
  u64 impl;
  small_vector_u64(u64 impl_ = 0) : impl(impl_) {}
  constexpr u64 mask() const { return (1ULL << bits) - 1; }

  struct Subst {
    small_vector_u64& x;
    int i;
    Subst(small_vector_u64& x_, int i_) : x(x_), i(i_) {}
    Subst operator=(ll t) { x.set(i, t); return *this; }
    operator ll() const { return x.at(i); }
  };

  ll set(ll i, ll t) {
    impl &= ~(mask() << (i * bits));
    impl |= t << (i * bits);
    return t;
  }

  ll at(ll i) const { return (impl >> (i * bits)) & mask(); }
  Subst rs(ll i) { return Subst(*this, i); }
  ll operator[](ll i) const { return at(i); }
  Subst operator[](ll i) { return rs(i); }

  bool operator==(const small_vector_u64& o) const { return impl == o.impl; }
  operator u64() const { return impl; }

  string show(int len=-1) const {
    string ret = "[";
    if (len < 0) len = 64 / bits;
    for (ll i = 0; i < len; i++) {
      if (i > 0) ret += ", ";
      ret += to_string(at(i));
    }
    ret += ']';
    return ret;
  }

  friend ostream& operator<<(ostream& os, const small_vector_u64& vec) { return os << vec.show(); }
};

template <int bits>
struct safe_custom_hash<small_vector_u64<bits>, void> {
  size_t operator()(const small_vector_u64<bits>& x) const {
    return safe_custom_hash<u64>{}(u64(x));
  }
};

struct small_vector_string {
  string impl;
  small_vector_string() : impl() {}
  small_vector_string(ll sz, ll init = 0) : impl(sz, (char)init) {}
  small_vector_string(const string& impl_) : impl(impl_) {}
  small_vector_string(string&& impl_) : impl(move(impl_)) {}

  // We employ Subst struct so that "cerr << vec[0];" produces "0" rather than "^@".
  struct Subst {
    small_vector_string& x;
    int i;
    Subst(small_vector_string& x_, int i_) : x(x_), i(i_) {}
    Subst operator=(ll t) { x.impl[i] = t; return *this; }
    operator ll() const { return ll(x.impl[i]); }
  };

  ll operator[](ll i) const { return impl[i]; }
  Subst operator[](ll i) { return Subst(*this, i); }

  bool operator==(const small_vector_string& o) const { return impl == o.impl; }
  operator string() const { return impl; }

  string show() const {
    string ret = "[";
    for (ll i = 0; i < ssize(impl); i++) {
      if (i > 0) ret += ", ";
      ret += to_string(impl[i]);
    }
    ret += ']';
    return ret;
  }

  friend ostream& operator<<(ostream& os, const small_vector_string& vec) { return os << vec.show(); }
};

template <>
struct safe_custom_hash<small_vector_string, void> {
  size_t operator()(const small_vector_string& x) const {
    return safe_custom_hash<string>{}(string(x));
  }
};



// ---- end smallVec.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> pow6(6);
  pow6[0] = 1;
  REP(i, 1, 6) pow6[i] = pow6[i - 1] * 6;

  vector<ll> A(6);
  REP(i, 0, 6) cin >> A[i];

  using svu = small_vector_u64<3>;
  vector<safe_umap<svu, double>> tbl(3);
  auto f = [&](auto rF, ll lev, svu keep, ll keep_size) -> double {
    auto [it, rc] = tbl[lev].try_emplace(keep, 0.0);
    double& ret = it->second;
    if (rc) {
      ret = 0.0;
      ll b = 5 - keep_size;
      IntDupPerm dip(6, b);
      while (dip.get()) {
        double e = 0.0;
        if (lev == 0) {
          svu v = keep;
          REP(i, 0, b) v[dip[i]] = v[dip[i]] + 1;
          REP(j, 0, 6) {
            ll this_e = 0;
            REP(k, 0, 6) if (A[j] == A[k]) this_e += A[j] * v[k];
            e = max(e, (double)this_e);
          }
        }else {
          REP(x, 0, 1LL << b) {
            svu v = keep;
            REP(i, 0, b) if (x >> i & 1) v[dip[i]] = v[dip[i]] + 1;
            double this_e = rF(rF, lev - 1, v, keep_size + popcount((u64)x));
            e = max(e, this_e);
          }
        }
        ret += e / (double)pow6[b];
      }
    }
    return ret;
  };

  svu empty;
  double ans = f(f, 2, empty, 0);
  cout << ans << endl;

  return 0;
}

