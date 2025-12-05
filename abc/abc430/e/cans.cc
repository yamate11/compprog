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

// @@ !! LIM(unordered_map rollingHash)

// ---- inserted library file unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

  template<typename RandomIt>
  void shuffle(RandomIt first, RandomIt last) { std::shuffle(first, last, rng); }

};

random_device Random::the_random_device;

// ---- end random.cc

// ---- inserted library file rollingHash.cc

// By keymoon
//     https://qiita.com/keymoon/items/11fac5627672a6d6a9f6

using u64 = unsigned long long;

constexpr u64 rh_prime = (1ULL << 61) - 1;
constexpr u64 rh_mask30 = (1ULL << 30) - 1;
constexpr u64 rh_mask31 = (1ULL << 31) - 1;
constexpr u64 rh_mask61 = (1ULL << 61) - 1;
constexpr u64 rh_positivizer = rh_prime * 4;

u64 rh_mul_nomod(u64 a, u64 b) {
  u64 au = a >> 31;
  u64 ad = a & rh_mask31;
  u64 bu = b >> 31;
  u64 bd = b & rh_mask31;
  u64 c = ad * bu + au * bd;
  u64 cu = c >> 30;
  u64 cd = c & rh_mask30;
  return au * bu * 2 + cu + (cd << 31) + ad * bd;
}

u64 rh_calc_mod(u64 x) {
  u64 xu = x >> 61;
  u64 xd = x & rh_mask61;
  u64 res = xu + xd;
  if (res >= rh_prime) res -= rh_prime;
  return res;
}

u64 rh_add(u64 a, u64 b) {
  u64 x = a + b;
  return x >= rh_prime ? x - rh_prime : x;
}
u64 rh_subt(u64 a, u64 b) { return (a < b) ? rh_prime + a - b : a - b; }
u64 rh_mul(u64 a, u64 b) { return rh_calc_mod(rh_mul_nomod(a, b)); }

struct RHVal {
  u64 u64v;
  RHVal(u64 t = 0) : u64v(t) {
#if DEBUG
    if (t >= rh_prime) throw runtime_error("out of range for RHVal");
#endif
  }
  RHVal(const RHVal& o) : u64v(o.u64v) {}
  RHVal& operator =(const RHVal& o) { u64v = o.u64v;  return *this; }
  RHVal& operator =(u64 t) {
#if DEBUG
    if (t >= rh_prime) throw runtime_error("out of range for RHVal");
#endif
    u64v = t;
    return *this;
  }

  explicit operator u64() const { return u64v; }

  bool operator ==(const RHVal& o) const { return u64v == o.u64v; }
  bool operator !=(const RHVal& o) const { return not (*this == o); }

  RHVal& operator +=(const RHVal& o) { u64v = rh_add(u64v, o.u64v); return *this; }
  RHVal& operator -=(const RHVal& o) { u64v = rh_subt(u64v, o.u64v); return *this; }
  RHVal& operator *=(const RHVal& o) { u64v = rh_mul(u64v, o.u64v); return *this; }

  friend RHVal operator +(RHVal a, const RHVal& b) { return a += b; }
  friend RHVal operator -(RHVal a, const RHVal& b) { return a -= b; }
  friend RHVal operator *(RHVal a, const RHVal& b) { return a *= b; }
  friend RHVal operator -(const RHVal& b) { return RHVal(0ULL) - b; }

  friend ostream& operator<< (ostream& os, const RHVal& t) {
    os << t.u64v;
    return os;
  }
};

template<typename elem_t = char, typename conv_t = nullptr_t>
struct RollingHashGen {
  
  vector<RHVal> pow_memo;
  RHVal base;
  conv_t conv;

  void _initialize(RHVal base_, RHVal min_base_) {
    pow_memo = vector<RHVal>{1};
    if (base_ == 0) base = Random().range((u64)min_base_, 1ULL << 59);
    else            base = base_;
  }

  RollingHashGen(RHVal base_ = 0, RHVal min_base_ = 1000) { _initialize(base_, min_base_); }
  RollingHashGen(RHVal base_, RHVal min_base_, conv_t conv_) : conv(conv_) { _initialize(base_, min_base_); }

  void set_conv(conv_t conv_) { conv = conv_; }

  struct HashValues {
    RollingHashGen* rh;
    vector<RHVal> vs;

    HashValues() {}
    HashValues(RollingHashGen* rh_, const vector<RHVal>& s) : rh(rh_), vs(s) {}

    RHVal get(int start = 0, int len = -1) const {
      if (len == -1) len = vs.size() - 1 - start;
      if (start == 0) return vs[len];
      return rh_calc_mod((u64)vs[start + len] + rh_positivizer
                         - rh_mul_nomod((u64)vs[start], (u64)rh->base_power(len)));
    }
  };

  vector<RHVal> _hashes(const auto& s) const {
    vector<RHVal> vs(s.size() + 1, RHVal(0ULL));
    for (int i = 0; i < ssize(s); i++) {
      RHVal e;
      if constexpr (is_same<conv_t, nullptr_t>::value) {
        e = static_cast<RHVal>(s[i]);
      } else {
        e = conv(s[i]);
      }
      vs[i+1] = rh_calc_mod(rh_mul_nomod((u64)vs[i], (u64)base) + (u64)e);
    }
    return vs;
  }
  vector<RHVal> _hashes(const char* p) const { return _hashes(string(p)); }

  HashValues precomp(const auto& s) { return HashValues(this, _hashes(s)); }
  RHVal hashvalue(const auto& s) { return HashValues(this, _hashes(s)).vs.back(); }

  RHVal base_power(ll n) {
    while ((int)pow_memo.size() < n + 1) {
      pow_memo.push_back(pow_memo[pow_memo.size() - 1] * base);
    }
    return pow_memo[n];
  }

  RHVal hash_concat(RHVal hash1, RHVal hash2, int len2) {
    return hash1 * base_power(len2) + hash2;
  }

};


using RollingHash = RollingHashGen<char, nullptr_t>;

template<typename T>
auto make_rolling_hash_gen(ll base, ll min_base, auto conv) {
  return RollingHashGen<T, decltype(conv)>(base, min_base, conv);
}

template <>
struct safe_custom_hash<RHVal, void> {
  size_t operator()(const RHVal& x) const { return safe_custom_hash<u64>{}((u64)x); }
};


// ---- end rollingHash.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  RollingHash rh;

  auto solve = [&]() -> ll {
    string A; cin >> A;
    string B; cin >> B;
    ll sz = ssize(A);
    auto hsA = rh.precomp(A);
    auto hsB = rh.precomp(B);
    RHVal hB = hsB.get();
    if (hB == hsA.get()) return 0;
    REP(i, 1, sz) {
      RHVal h = rh.hash_concat(hsA.get(i, sz - i), hsA.get(0, i), i);
      if (h == hB) return i;
    }
    return -1;

  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

