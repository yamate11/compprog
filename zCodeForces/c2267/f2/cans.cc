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

// @@ !! LIM(digit unordered_map)

// ---- inserted library file digit.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/digit.cc

struct digit_error : runtime_error {
  digit_error(const string& msg) : runtime_error(msg) {}
};

struct digit_util {
  const ll base;
  const vector<ll> _pow;

  static vector<ll> _make_pow(ll b) {
    vector<ll> ret;
    ll t = 1;
    while (true) {
      ret.push_back(t);
      if (__builtin_smulll_overflow(t, b, &t)) break;
    }
    return ret;
  };

  void range_error(string meth, ll param) const {
    throw digit_error(format("digit.{}: parameter {} out of range", meth, param));
  }

#if DEBUG
  ll zero_warning(string meth, bool quiet) const {
    if (not quiet) {
      cerr << format("You called {} with parameter 0.  It returns 0.  If this is OK, considter quiet=true.", meth)
           << endl;
    }
    return 0;
  }
#else
  ll zero_warning(string, bool) const { return 0; }
#endif

  digit_util(ll base_ = 10) : base(base_), _pow(_make_pow(base_)) {}
    
  ll pow_size() const { return _pow.size(); }
  ll pow(ll i) const {
    if (i < 0 or ssize(_pow) <= i) range_error("pow", i);
    return _pow[i];
  }

  ll width(ll x, bool quiet = false) const {
    if (x < 0) range_error("width", x);
    if (base == 2) return bit_width((unsigned long long)x);
    if (x == 0) return zero_warning("width", quiet);
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i, bool quiet = false) const {
    if (i < 0) range_error("nd_min", i);
    if (i == 0) return zero_warning("nd_min", quiet);
    return pow(i - 1);
  }
  ll nd_max(ll i, bool quiet = false) const {
    if (i < 0) range_error("nd_max", i);
    if (i == 0) return zero_warning("nd_max", quiet);
    return nd_min(i + 1) - 1;
  }

  ll floor(ll x, bool quiet = false) const {
    if (x < 0) range_error("floor", x);
    if (x == 0) return zero_warning("floor", quiet);
    return pow(width(x) - 1);
  }
  ll ceil(ll x, bool quiet = false) const {
    if (x < 0) range_error("ceil", x);
    if (x == 0) return zero_warning("ceil", quiet);
    ll p = pow(width(x) - 1);
    return x == p ? p : pow(width(x));
  }

  ll log(ll x) const {
    if (x <= 0) range_error("log", x);
    return width(x) - 1;
  }

  ll d_at(ll x, ll i) const {
    if (x < 0) range_error("d_at", x);
    if (x == 0) return 0;
    if (i < 0) i += width(x);
    return (x / pow(i)) % base;
  }

  ll d_sub(ll x, ll pos, ll len) const {
    if (x < 0) range_error("d_sub", x);
    if (x == 0) return 0;
    ll w = width(x);
    if (pos < 0) pos += w;
    if (len < 0) { len = -len; pos = pos - len + 1; }
    if (pos < 0) { len += pos; pos = 0; }
    if (pos + len > w) len = w - pos;
    return (x % pow(pos + len)) / pow(pos);
  }

  template<bool big_endian>
  vector<ll> _gen_to_vector(ll x) const {
    if (x < 0) range_error("to_vector", x);
    if (x == 0) return vector<ll>{0};
    ll w = width(x);
    vector<ll> ret(w);
    for (int i = 0; i < w; i++) {
      if constexpr (big_endian) ret[w - 1 - i] = x % base;
      else                      ret[i]         = x % base;
      x /= base;
    }
    return ret;
  }
  vector<ll> to_vector(ll x) const { return _gen_to_vector<false>(x); }
  vector<ll> to_vector_big_endian(ll x) const { return _gen_to_vector<true>(x); }

  template<bool big_endian>
  ll _gen_from_vector(const auto& vec) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(vec); i++) {
      ll j;
      if constexpr (big_endian) j = ssize(vec) - 1 - i; else j = i;
      ret += vec[j] * pow(i);
    }
    return ret;
  }
  ll from_vector(const auto& vec) const { return _gen_from_vector<false>(vec); }
  ll from_vector_big_endian(const auto& vec) const { return _gen_from_vector<true>(vec); }

  string to_string(ll x, bool upcase = false) const {
    if (x < 0) range_error("to_string", x);
    if (x == 0) return string("0");
    char ten = upcase ? 'A' : 'a';
    ll w = width(x);
    string ret(w, ' ');
    for (ll i = w - 1; x != 0; x /= base, i--) {
      ll y = x % base;
      ret[i] = y < 10 ? '0' + y : ten + (y - 10);
    }
    return ret;
  }

  string to_string_padding(ll x, ll width, char c = '0', bool upcase = false) const {
    string s = to_string(x, upcase);
    if (ssize(s) >= width) return s;
    return string(width - ssize(s), c) + s;
  }

  static ll _get_digit_char(char c) {
    if ('0' <= c and c <= '9')      return c - '0';
    else if ('a' <= c and c <= 'z') return c - 'a' + 10;
    else if ('A' <= c and c <= 'Z') return c - 'A' + 10;
    else throw runtime_error("_get_digit_char: unknown letter");
  }

  ll from_string(string s) const {
    ll ret = 0;
    for (ll i = 0; i < ssize(s); i++) ret += _get_digit_char(s[i]) * pow(ssize(s) - 1 - i);
    return ret;
  }


};

// ---- end digit.cc

// ---- inserted library file unordered_map.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/unordered_map.cc

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

// For tuple
template <typename... Ts>
struct safe_custom_hash<tuple<Ts...>, void> {
  size_t operator()(const tuple<Ts...>& x) const { return impl(x, index_sequence_for<Ts...>{}); }
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
  template <size_t... Is>
  static size_t impl(const tuple<Ts...>& x, index_sequence<Is...>) {
    static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
    static const array<uint64_t, sizeof...(Ts)> coef = { (splitmix64(frand + Is) | 1)... };
    uint64_t h = 0;
    (
      void( h += coef[Is] * uint64_t(safe_custom_hash<tuple_element_t<Is, tuple<Ts...>>>{}(get<Is>(x))) ),
      ...
    );
    return h;
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

  digit_util du2(2);

  auto solve = [&]() -> void {
    ll N, Q; cin >> N >> Q;

    auto f = [&](const auto& A) -> vector<ll> {
      ll w0 = du2.width(A.back());
      vector<ll> ret;
      auto g = [&]() -> ll {
        REP(w, 1, w0 + 1) {
          // vector<ll> C(1LL << w, 0LL);
          safe_umap<ll, ll> C;
          REP(i, 0, N) {
            ll k = A[i] >> (w0 - w) & ((1LL << w) - 1);
            C[k]++;
          }
          ll s = 0;
          for (auto [k, n] : C) s += n * (n - 1) / 2;
          if (s < N) return w - 1;
        }
        return -1;
      };
      ll w1 = g();
      if (w1 < 0) return vector<ll>{};
      safe_umap<ll, vector<ll>> D;
      REP(i, 0, N) {
        ll k = A[i] >> (w0 - w1) & ((1LL << w1) - 1);
        D[k].push_back(A[i]);
      }
      for (auto& [k, d] : D) {
        REP(i, 0, ssize(d)) REP(j, i + 1, ssize(d)) ret.push_back(d[i] xor d[j]);
      }
      ranges::sort(ret);
      ret.resize(N);
      return ret;
    };

    // @InpVec(N, A) [IJ8VAUox]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [IJ8VAUox]

    ranges::sort(A);

    vector<ll> P;
    while (true) {
      ll v = A.back() - A.front();
      if (v == 0) break;
      P.push_back(v);
      A = f(A);
      if (A.empty()) break;
    }
    REP(_q, 0, Q) {
      ll x; cin >> x;
      ll ans = x >= ssize(P) ? 0 : P[x];
      cout << ans << "\n";
    }

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

