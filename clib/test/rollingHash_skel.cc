#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(rollingHash)

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
    RollingHash rh = make_rolling_hash(rng2);
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
    RollingHash rh = make_rolling_hash(rng2);
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

  {
    int lim = 1e5;
    uniform_int_distribution<int> dist(-lim, lim);
    auto hash_elem = [&](int x) -> u64 { return x + lim; };
    auto rh = make_rolling_hash_gen(hash_elem, rng2);
    int sz = 1e4;
    vector<int> v(sz);
    for (int i = 0; i < sz; i++) v[i] = dist(rng2);
    int p0 = 3712;
    int q0 = 5438;
    int len = 1e3;
    for (int j = 0; j < len; j++) v[p0 + j] = v[q0 + j];
    auto hs = rh.hashes(v);
    for (ll i = 0; i < sz - len; i++) {
      for (ll j = i + 1; j < sz - len; j++) {
        if (i == p0 && j == q0) {
          assert(rh.get(hs, i, len) == rh.get(hs, j, len));
        }else {
          assert(rh.get(hs, i, len) != rh.get(hs, j, len));
        }
      }
    }
  }


  // WeakRH rh{};
  // U128RH rh{};
  RollingHash rh = make_rolling_hash(rng2);

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
