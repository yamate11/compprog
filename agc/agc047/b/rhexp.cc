#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --


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


// By keymoon
// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
struct RollingHash {
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
    rng.seed(time(0));
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
mt19937 RollingHash::rng;


int main(int argc, char *argv[] ) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  static mt19937 rng2;
  rng2.seed(time(0));
  uniform_int_distribution<> dist(int('a'), int('z') + 1);
  auto genstr = [&]() -> string {
    string s;
    for (ll i = 0; i < 40; i++) {
      s += char(dist(rng2));
    }
    return s;
  };

  // RollingHash rh{};
  WeakRH rh{};

  using u64 = unsigned long long;
  map<u64, string> mp;
  while (true) {
    string s = genstr();
    ll i = rh.reg(s);
    ll hash = rh.get_hash(i, 0, s.size());
    if (mp.find(hash) != mp.end() && mp[hash] != s) {
      cout << i << endl;
      cout << hash << endl;
      cout << mp[hash] << endl;
      cout << s << endl;
      return 0;
    }
    mp[hash] = s;
  }



  return 0;
}

