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

// @@ !! LIM(rollingHash)

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

template<typename elem_t = char, typename conv_t = nullptr_t>
struct RollingHashGen {
  
  vector<u64> pow_memo;
  u64 base;
  conv_t conv;

  void _initialize(u64 base_, u64 min_base_) {
    pow_memo = vector<u64>({1});
    if (base_ == 0) base = Random().range(min_base_, 1ULL << 59);
    else            base = base_;
    if (base >= rh_prime) { throw runtime_error("RollingHashGen::_initialize: invalid base"); }
  }

  RollingHashGen(u64 base_ = 0, u64 min_base_ = 1000) { _initialize(base_, min_base_); }
  RollingHashGen(u64 base_, u64 min_base_, conv_t conv_) : conv(conv_) { _initialize(base_, min_base_); }

  void set_conv(conv_t conv_) { conv = conv_; }

  vector<u64> hashes(const auto& s) {
    int n = s.size();
    vector<u64> ret(n+1);
    for (int i = 0; i < n; i++) {
      u64 e;
      if constexpr (is_same<conv_t, nullptr_t>::value) {
        e = static_cast<u64>(s[i]);
      } else {
        e = conv(s[i]);
      }
      ret[i+1] = rh_calc_mod(rh_mul_nomod(ret[i], base) + e);
    }
    return ret;
  }

  vector<u64> hashes(const char* p) { return hashes(string(p)); }

  u64 base_power(ll n) {
    while ((int)pow_memo.size() < n + 1) {
      pow_memo.push_back(rh_mul(pow_memo[pow_memo.size() - 1], base));
    }
    return pow_memo[n];
  }

  u64 get(const vector<u64>& hashes, int start = 0, int len = -1) {
    if (len == -1) len = hashes.size() - 1 - start;
    if (start == 0) return hashes[len];
    return rh_calc_mod(hashes[start + len] + 
                       rh_positivizer - rh_mul_nomod(hashes[start], base_power(len)));
  }

  u64 hashvalue(const auto& s) { return hashes(s).back(); }

  u64 hash_concat(u64 hash1, u64 hash2, int len2) {
    return rh_add(rh_mul(hash1, base_power(len2)), hash2);
  }

};

using RollingHash = RollingHashGen<char, nullptr_t>;

template<typename T>
auto make_rolling_hash_gen(ll base, ll min_base, auto conv) {
  return RollingHashGen<T, decltype(conv)>(base, min_base, conv);
}

// ---- end rollingHash.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  RollingHash rh;

  ll lim = 5e5 + 10;
  ll Q; cin >> Q;
  ll ans = 0;
  vector<unordered_set<u64>> Xs(lim);
  // vector<string> Ys;
  vector<bool> Yeff;
  vector<unordered_map<u64, vector<ll>>> Ypreps(lim);
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    string s; cin >> s;
    ll slen = ssize(s);
    if (tp == 1) {
      vector<u64> hs = rh.hashes(s);
      u64 h = rh.get(hs);
      if (not Xs[slen].contains(h)) {
        Xs[slen].insert(h);
        auto it = Ypreps[slen].find(h);
        if (it != Ypreps[slen].end()) {
          for (auto i : it->second) {
            if (Yeff[i]) {
              Yeff[i] = false;
              ans--;
            }
          }
        }
      }
    }else if (tp == 2) {
      vector<u64> hs = rh.hashes(s);
      ll len = ssize(s);
      bool found = false;
      REP(x, 1, len + 1) {
        u64 h = rh.get(hs, 0, x);
        if (Xs[x].contains(h)) {
          found = true;
          break;
        }
      }
      if (not found) {
        ans++;
        ll i0 = ssize(Yeff);
        Yeff.push_back(true);
        REP(x, 1, len + 1) {
          u64 h = rh.get(hs, 0, x);
          Ypreps[x][h].push_back(i0);
        }
      }
    }else assert(0);
    cout << ans << "\n";
  }

  return 0;
}

