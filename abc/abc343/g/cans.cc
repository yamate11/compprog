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

// @@ !! LIM(forall rollingHash f:updMaxMin)

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

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

  vector<u64> hashes(auto s) {
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

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [Pjbt4tQR]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [Pjbt4tQR]
  ll except_words = 0LL;

  RollingHash rh;
  vector<vector<u64>> vec(N);
  REP(i, 0, N) vec[i] = rh.hashes(S[i]);
  vector dist(N, vector(N, 0LL));
  REP(i_tmp, 0, N) {
    REP(j_tmp, i_tmp + 1, N) {
      ll i0, j0;
      if (ssize(S[i_tmp]) < ssize(S[j_tmp])) { i0 = j_tmp; j0 = i_tmp; }
      else                                   { i0 = i_tmp; j0 = j_tmp; }
      ll len_i = ssize(S[i0]);
      ll len_j = ssize(S[j0]);
      REP(k, 0, len_i - len_j + 1) {
        if (rh.get(vec[i0], k, len_j) == rh.get(vec[j0], 0, len_j)) { except_words |= (1LL << j0); }
      }
      dist[i0][j0] = ssize(S[j0]);
      dist[j0][i0] = ssize(S[i0]);
      REP(k, 1, len_j) {
        if (rh.get(vec[j0], k, len_j - k) == rh.get(vec[i0], 0, len_j - k)) {
          dist[j0][i0] = len_i - (len_j - k);
          break;
        }
      }
      REP(k, len_i - len_j + 1, len_i) {
        if (rh.get(vec[i0], k, len_i - k) == rh.get(vec[j0], 0, len_i - k)) {
          dist[i0][j0] = len_j - (len_i - k);
          break;
        }
      }
    }
  }
  ll big = 1e18;
  vector sdist(1LL << N, vector(N, big));
  REP(i, 0, N) if (not (except_words >> i & 1)) sdist[except_words | (1LL << i)][i] = ssize(S[i]);
  REP(x, 1, 1LL << N) {
    if (~x & except_words) continue;
    REP(i, 0, N) if (not (except_words >> i & 1)) {
      REP(j, 0, N) if (not (x >> j & 1)) {
        updMin(sdist[x | (1LL << j)][j], sdist[x][i] + dist[i][j]);
      }
    }
  }
  ll ans = big;
  REP(i, 0, N) updMin(ans, sdist[(1LL << N) - 1][i]);
  cout << ans << endl;

  return 0;
}

