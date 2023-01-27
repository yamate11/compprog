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

// @@ !! LIM(rollingHash)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string T; cin >> T;
  string T1 = T.substr(N);
  reverse(ALL(T1));
  string TT = T.substr(0, N) + T1;
  
  random_device rand_dev;
  mt19937 rng(rand_dev());
  RollingHash rh = make_rolling_hash(rng);
  vector<u64> hs = rh.hashes(TT);
  ll i0 = -1;
  REP(i, 0, N) if (rh.get(hs, 0, i) == rh.get(hs, 2*N - i, i) and rh.get(hs, i, N - i) == rh.get(hs, N, N - i)) {
    i0 = i;
    break;
  }
  if (i0 < 0) cout << -1 << endl;
  else cout << T.substr(0, i0) + T.substr(N + i0) << endl << i0 << endl;

  return 0;
}

