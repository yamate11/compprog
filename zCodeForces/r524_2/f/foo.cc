#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(rollingHash)
// --> rollingHash
// ---- inserted library file rollingHash.cc

// By keymoon
//     https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
using u64 = unsigned long long;

struct RollingHash {
  static random_device rand_dev;
  static mt19937 rng;

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

  // vector<vector<u64>> hash;
  vector<u64> pow_memo;
  u64 base;

  RollingHash() : pow_memo({1}) {
    uniform_int_distribution<> dist(1000, 1ULL << 20);
    base = dist(rng);
  }

  vector<u64> hashes(string s) {
    int n = s.size();
    vector<u64> ret(n+1);
    for (int i = 0; i < n; i++) {
      ret[i+1] = calc_mod(mul(ret[i], base) + s[i]);
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

  u64 hash_char(char c) { return c; }

  /*
  int reg(string s) {
    int n = s.size();
    vector<u64> hs(n+1);
    for (int i = 0; i < n; i++) {
      hs[i+1] = calc_mod(mul(hs[i], base) + s[i]);
    }
    hash.push_back(move(hs));
    while ((int)pow_memo.size() < n + 1) {
      pow_memo.push_back(calc_mod(mul(pow_memo[pow_memo.size() - 1], base)));
    }
    return hash.size() - 1;
  }

  u64 get_hash(int idx, int start, int len) {
    return calc_mod(hash[idx][start + len] + 
		    positivizer - mul(hash[idx][start], pow_memo[len]));
  }
  */

};
random_device RollingHash::rand_dev;
mt19937 RollingHash::rng(RollingHash::rand_dev());

// ---- end rollingHash.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s(256, '.');
  for (ll i = -128; i <= 127; i++) s[128 + i] = i;
  cout << s.size() << endl;

  RollingHash rh;
  cout << rh.hash_char(-127) << endl;

  return 0;
}

