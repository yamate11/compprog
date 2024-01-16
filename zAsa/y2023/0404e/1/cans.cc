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

// @@ !! LIM(rollingHash forall)

// ---- inserted library file rollingHash.cc

// By keymoon
//     https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
using u64 = unsigned long long;

template<typename F>
struct RollingHashTemp {
  static constexpr u64 mod    = (1ULL << 61) - 1;
  static constexpr u64 mask30 = (1ULL << 30) - 1;
  static constexpr u64 mask31 = (1ULL << 31) - 1;
  static constexpr u64 mask61 = (1ULL << 61) - 1;
  static constexpr u64 positivizer = mod * 4;
  
  static u64 mul(u64 a, u64 b) {
    u64 au = a >> 31;
    u64 ad = a & mask31;
    u64 bu = b >> 31;
    u64 bd = b & mask31;
    u64 c = ad * bu + au * bd;
    u64 cu = c >> 30;
    u64 cd = c & mask30;
    return au * bu * 2 + cu + (cd << 31) + ad * bd;
  }
  
  static u64 calc_mod(u64 x) {
    u64 xu = x >> 61;
    u64 xd = x & mask61;
    u64 res = xu + xd;
    if (res >= mod) res -= mod;
    return res;
  }

  F hash_elem;
  vector<u64> pow_memo;
  u64 base;

  RollingHashTemp(F hash_elem_, mt19937 rng)
    : hash_elem(hash_elem_), pow_memo({1}) {
    uniform_int_distribution<> dist(1000, 1ULL << 20);
    base = dist(rng);
  }

  vector<u64> hashes(auto s) {
    int n = s.size();
    vector<u64> ret(n+1);
    for (int i = 0; i < n; i++) {
      ret[i+1] = calc_mod(mul(ret[i], base) + hash_elem(s[i]));
    }
    return ret;
  }

  u64 base_power(ll n) {
    while ((int)pow_memo.size() < n + 1) {
      pow_memo.push_back(calc_mod(mul(pow_memo[pow_memo.size() - 1], base)));
    }
    return pow_memo[n];
  }

  u64 get(const vector<u64>& hashes, int start = 0, int len = -1) {
    if (len == -1) len = hashes.size() - 1 - start;
    if (start == 0) return hashes[len];
    return calc_mod(hashes[start + len] + 
		    positivizer - mul(hashes[start], base_power(len)));
  }

  u64 hash_concat(u64 hash1, u64 hash2, int len2) {
    return calc_mod(calc_mod(mul(hash1, base_power(len2))) + hash2);
  }

  // u64 hash_char(char c) { return (unsigned char)c; }

};

auto make_rolling_hash_gen(auto hash_elem, mt19937 rng)
  -> RollingHashTemp<decltype(hash_elem)> {
  return RollingHashTemp(hash_elem, rng);
}

u64 hash_char(char c) { return (unsigned char)c; }

using RollingHash = RollingHashTemp<decltype(&hash_char)>;
RollingHash make_rolling_hash(mt19937 rng) {
  return RollingHash(&hash_char, rng);
}

// ---- end rollingHash.cc

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> fib{1, 1};
  {
    ll i = 0;
    while (true) {
      ll x = fib[i] + fib[i + 1];
      fib.push_back(x);
      if (x > 20000) break;
      i++;
    }
  }

  random_device rand_dev;
  mt19937 rng(rand_dev());
  RollingHash rh = make_rolling_hash(rng);
  string S; cin >> S;
  ll sz = SIZE(S);
  ll i0 = EXFIND(i, 0, SIZE(fib), fib[i] == sz);
  auto hs = rh.hashes(S);
  u64 h = rh.get(hs, 0, 1);

  ll p = 0;
  auto func = [&](auto rF, ll p, ll i0) -> pll {
    assert(i0 > 0);
    if (i0 == 1) return {1, 0};
    if (i0 == 2) 

    ll i = i0 - 3;
    if (rh.get(hs, p + fib[i], fib[i + 1]) == rh.get(hs, p + fib[i + 2], fib[i + 1])) {
      auto [n, k] = rF(rF, p + fib[i], i - 2);
      return {n + 2, k * 4 + 2};
    }else if (rh.get(hs, p, fib[i + 1]) == rh.get(hs, p + fib[i + 1], fib[i + 1])) {
      auto [n, k] = rF(rF, p, i - 2);
      return {n + 2, k * 4 + 1};
    }else if (rh.get(hs, p, fib[i + 1]) == rh.get(hs, p + fib[i + 2], fib[i + 1])) {
      auto [n, k] == rF(rF, p, i - 2);
      return {n + 2, k * 4};
    }else assert(0);
  }

  return 0;
}

