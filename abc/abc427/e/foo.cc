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

// @@ !! LIM(unordered_map random f:perfmeas)

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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int main() {
  Random rand;

  ll N = 1e6;
  ll big = 1e18;

  vector<ll> data(N);
  REP(i, 0, N) data[i] = rand.range(0, big);

  double t1 = get_time_sec();
  safe_umap<ll, ll> mp1;
  mp1.reserve(N * 2);
  REP(i, 0, N) mp1[data[i]]++;
  double t2 = get_time_sec();

  gp_hash_table<ll, ll, safe_custom_hash<ll>, equal_to<ll>,
                direct_mask_range_hashing<>,
                linear_probe_fn<>, hash_standard_resize_policy<
                  hash_exponential_size_policy<>,
                                     hash_load_check_resize_trigger<>,
                                     true>> mp2;
  // safe_umap<ll, ll, true> mp2;
  // mp2.reserve(N * 1.3);
  // mp2.resize(1LL << 20);
  REP(i, 0, N) mp2[data[i]]++;
  double t3 = get_time_sec();

  cerr << t2 - t1 << endl;
  cerr << t3 - t2 << endl;


  return 0;
}

