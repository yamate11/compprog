#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Rolling Hash

  RollingHash rh;
  string s = "Hello, world.";
  int idx = rh.reg(s);
  unsigned long long hash = rh.get_hash(idx, 7, 4);
     // Returns the hash for s.substr(7, 4), i.e. 'worl'
 */

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- rollingHash.cc

// By keymoon
//     https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
struct RollingHash {
  static random_device rand_dev;
  static mt19937 rng;

  using u64 = unsigned long long;
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

  vector<vector<u64>> hash;
  vector<u64> pow_memo;
  u64 base;

  RollingHash() : hash(), pow_memo({1}) {
    uniform_int_distribution<> dist(1000, 1ULL << 20);
    base = dist(rng);
  }

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

};
random_device RollingHash::rand_dev;
mt19937 RollingHash::rng(RollingHash::rand_dev());

// @@ !! END ---- rollingHash.cc


struct WeakRH {
  using u64 = unsigned long long;
  static constexpr u64 mod = (1ULL << 31) - 1;

  vector<vector<u64>> hash;
  vector<u64> pow_memo;
  const u64 base;

  WeakRH() : hash(), pow_memo({1}), base(4719527) {}

  int reg(string s) {
    int n = s.size();
    vector<u64> hs(n+1);
    for (int i = 0; i < n; i++) {
      hs[i+1] = (hs[i] * base + s[i]) % mod;
    }
    hash.push_back(move(hs));
    while ((int)pow_memo.size() < n + 1) {
      pow_memo.push_back((pow_memo[pow_memo.size() - 1] * base) % mod);
    }
    return hash.size() - 1;
  }

  u64 get_hash(int idx, int start, int len) {
    return (mod + hash[idx][start + len]
	    - ((hash[idx][start] * pow_memo[len]) % mod)) % mod;
  }

};

int main(int argc, char *argv[] ) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using u64 = unsigned long long;

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
    int idx1 = rh.reg(s1);
    int idx2 = rh.reg(s2);
    assert(rh.get_hash(idx1, 0, s1.size())
	   != rh.get_hash(idx2, 0, s2.size()));
    assert(rh.get_hash(idx1, 3, 3) == rh.get_hash(idx2, 2, 3));
  }

  {
    RollingHash rh;
    uniform_int_distribution<char> dist('0', '1');
    ll size = 100;
    string s(size, 0);
    for (ll i = 0; i < size; i++) {
      s[i] = dist(rng2);
    }
    ll idx = rh.reg(s);
    for (ll i = 0; i < size; i++) {
      for (ll j = i; j <= size; j++) {
	u64 hash1 = rh.get_hash(idx, i, j - i);
	string t = s.substr(i, j - i);
	ll idx2 = rh.reg(t);
	u64 hash2 = rh.get_hash(idx2, 0, j - i);
	assert(hash1 == hash2);
      }
    }
  }

  // WeakRH rh{};
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
    rh.reg("");
    ll idx = rh.reg(s);
    for (ll i = 0; i < 10; i++) {
      int p = dist_idx(rng2);
      int q = dist_idx(rng2);
      if (p > q) swap(p, q);
      string t = s.substr(p, q-p);
      u64 hash = rh.get_hash(idx, p, q-p);
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

