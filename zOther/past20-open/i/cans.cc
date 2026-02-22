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

// @@ !! LIM(smallVec)

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

  using sv = small_vector_u64<3>;
  sv goal;
  REP(i, 0, 8) goal[i] = i;
  sv init;
  REP(i, 0, 8) {
    ll x; cin >> x; x--;
    init[i] = x;
  }
  
  using sta = pair<sv, ll>;
  safe_uset<sv> visited;
  queue<sta> que;
  visited.insert(init);
  que.emplace(init, 0);
  while (not que.empty()) {
    auto [vec, d] = que.front(); que.pop();
    if (vec == goal) {
      cout << d << endl;
      return 0;
    }
    auto op = [&](ll x, ll y) -> void {
      auto new_vec = vec;
      new_vec[x] = (ll)vec[y];
      new_vec[y] = (ll)vec[x];
      if (not visited.contains(new_vec)) {
        visited.insert(new_vec);
        que.emplace(new_vec, d + 1);
      }
    };
    REP(i, 0, 4) op(i, i + 4);
    REP(i, 0, 2) REP(j, 0, 3) op(4 * i + j, 4 * i + j + 1);
  }
  assert(0);

  return 0;
}

