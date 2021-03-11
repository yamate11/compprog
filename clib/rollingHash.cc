#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Rolling Hash

  RollingHash rh;
  string s = "Hello, world.";

  auto hs = rh.hashes(s);
    // returned value hs is a vector<u64> of size s.size()+1.
    // hs[i] is the hash value of s.substr(0,i).
  u64 h = rh.get(hs, start, len)  // hash value of s.substr(start, len)

  string s1 = ..., s2 = ...;
  u64 h1 = rh.hashes(s1), h2 = rh.hashes(s2);
  u64 h12 = rh.hash_concat(h1, h2, s2.size());
    // h12 is the hash value of s1+s2.  Note that you need the size of s2.

  u64 ha = hash_char('a');   
    // hash value of a string of size 1.  
    // As a matter of fact, hash_char is an identity function.

 */

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- rollingHash.cc

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

// @@ !! END ---- rollingHash.cc


struct WeakRH {
  static constexpr u64 mod = (1ULL << 31) - 1;

  vector<u64> pow_memo;
  const u64 base;

  WeakRH() : pow_memo({1}), base(4719527) {}

  vector<u64> hashes(string s) {
    int n = s.size();
    vector<u64> hs(n+1);
    for (int i = 0; i < n; i++) {
      hs[i+1] = (hs[i] * base + s[i]) % mod;
    }
    return hs;
  }

  u64 get(const vector<u64>& hashes, int start = 0, int len = -1) {
    if (len == -1) len = hashes.size() - 1 - start;
    if (start == 0) return hashes[len];
    while ((int)pow_memo.size() < len + 1) {
      pow_memo.push_back(pow_memo[pow_memo.size() - 1] * base % mod);
    }
    return (hashes[start + len] +
	    mod - ((hashes[start] * pow_memo[len]) % mod)) % mod;
  }
};

struct U128RH {
  static random_device rand_dev;
  static mt19937 rng;
  static constexpr u64 mod = (1ULL << 61) - 1;
  
  vector<__uint128_t> pow_memo;
  const u64 base;

  u64 __get_base() {
    uniform_int_distribution<> dist(1000, 1ULL << 20);
    return dist(rng);
  }

  U128RH() : pow_memo({1}), base(__get_base()) {}

  vector<u64> hashes(string s) {
    int n = s.size();
    vector<u64> hs(n+1);
    for (int i = 0; i < n; i++) {
      hs[i + 1] = u64((__uint128_t(hs[i]) * base + s[i]) % mod);
    }
    return hs;
  }

  __uint128_t base_power(ll n) {
    while ((int)pow_memo.size() < n + 1) {
      pow_memo.push_back(pow_memo[pow_memo.size() - 1] * base % mod);
    }
    return pow_memo[n];
  }

  u64 get(const vector<u64>& hs, int start = 0, int len = -1) {
    if (len == -1) len = hs.size() - 1 - start;
    if (start == 0) return hs[len];
    return (hs[start + len] +
	    mod - (__uint128_t(hs[start]) * base_power(len)) % mod) % mod;
  }

  u64 hash_concat(u64 hash1, u64 hash2, int len2) {
    return u64((__uint128_t(hash1) * base_power(len2) % mod + hash2) % mod);
  }

  u64 hash_char(char c) { return c; }

};
random_device U128RH::rand_dev;
mt19937 U128RH::rng(U128RH::rand_dev());

int main(int argc, char *argv[] ) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng2(rd());

  if (argc != 2) {
    cerr << "Usage: ./rollingHash num\n  Appropriate num values are between 10 to 16.\n  10 * 2^num strings will be checked for collisions.\n  -O2 is recommended." << endl;
    exit(1);
  }

  {
    RollingHash rh;
    string s1 = "abcdefgh";
    string s2 = "XXdefYYYZZ";
    auto hashes1 = rh.hashes(s1);
    auto hashes2 = rh.hashes(s2);
    assert(rh.get(hashes1, 0, s1.size())
	   != rh.get(hashes2, 0, s2.size()));
    assert(rh.get(hashes1, 3, 3) == rh.get(hashes2, 2, 3));
    string s3 = "xyz";
    string s4 = "Axyz";
    string s5 = "xyzA";
    auto hashes3 = rh.hashes(s3);
    auto hashes4 = rh.hashes(s4);
    auto hashes5 = rh.hashes(s5);
    assert(rh.hash_concat('A', rh.get(hashes3), s3.size())
	   == rh.get(hashes4));
    assert(rh.hash_concat(rh.get(hashes3), 'A', 1) == rh.get(hashes5));
  }

  {
    RollingHash rh;
    uniform_int_distribution<char> dist('0', '1');
    ll size = 100;
    string s(size, 0);
    for (ll i = 0; i < size; i++) {
      s[i] = dist(rng2);
    }
    auto hashes0 = rh.hashes(s);
    for (ll i = 0; i < size; i++) {
      for (ll j = i; j <= size; j++) {
	u64 hash1 = rh.get(hashes0, i, j - i);
	string t = s.substr(i, j - i);
	auto hashes2 = rh.hashes(t);
	u64 hash2 = rh.get(hashes2, 0, j - i);
	assert(hash1 == hash2);
      }
    }
  }

  // WeakRH rh{};
  // U128RH rh{};
  RollingHash rh{};

  ll rep = 1LL << stoi(argv[1]);
  ll size = 100;
  uniform_int_distribution<char> dist('a', 'z');
  uniform_int_distribution<int> dist_idx(0, size-1);
  unordered_map<u64, string> mp;
  for (ll k = 0; k < rep; k++) {
    string s(size, 0);
    for (ll i = 0; i < size; i++) {
      for (ll j = 0; j < size; j++) s[j] = dist(rng2);
    }
    auto hashes = rh.hashes(s);
    for (ll i = 0; i < 10; i++) {
      int p = dist_idx(rng2);
      int q = dist_idx(rng2);
      if (p > q) swap(p, q);
      string t = s.substr(p, q-p);
      u64 hash = rh.get(hashes, p, q-p);
      auto it = mp.find(hash);
      if (it == mp.end()) {
	mp[hash] = t;
      }else if (it->second != t) {
	cerr << "collision!!!" << endl;
	cerr << "hash = " << hash << endl;
	cerr << "str1 = " << it->second << endl;
	cerr << "str2 = " << t << endl;
	exit(1);
      }
    }
  }
  cerr << "ok\n";
  
  return 0;
}

