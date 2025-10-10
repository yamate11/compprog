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

// @@ !! LIM(unordered_map)

// ---- inserted library file unordered_map.cc

/* This code is based on https://codeforces.com/blog/entry/62393 */

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
*/

template <typename T, typename Enable = void>
struct safe_custom_hash;

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

template <typename T_key, typename T_value>
using my_umap = unordered_map<T_key, T_value, safe_custom_hash<T_key>>;

template <typename T_key>
using my_uset = unordered_set<T_key, safe_custom_hash<T_key>>;

template <typename T_key>
using my_umultiset = unordered_multiset<T_key, safe_custom_hash<T_key>>;


// ---- end unordered_map.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<vector<ll>> S(4, vector<ll>(4));
  vector<vector<ll>> T(4, vector<ll>(4));
  REP(i, 0, 4) REP(j, 0, 4) {
    ll x; cin >> x;
    if (x >= 0) x--;
    S[i][j] = x;
  }
  REP(i, 0, 4) REP(j, 0, 4) {
    ll x; cin >> x;
    if (x >= 0) x--;
    T[i][j] = x;
  }

  ll lim = 15;
  vector<pll> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  auto on_board = [&](ll i, ll j) -> bool {
    return 0 <= i and i < 4 and 0 <= j and j < 4;
  };

  auto enc = [&](auto& v) -> string {
    string ret;
    REP(i, 0, 4) REP(j, 0, 4) {
      if (v[i][j] < 0) ret += '.';
      else ret += (char)('0' + v[i][j]);
    }
    return ret;
  };

  auto dec = [&](string& s) -> tuple<vector<vector<ll>>, ll, ll> {
    vector<vector<ll>> v(4, vector<ll>(4));
    ll i0 = -1, j0 = -1;
    REP(i, 0, 4) REP(j, 0, 4) {
      ll p = i * 4 + j;
      if (s[p] == '.') {
        v[i][j] = -1;
        i0 = i;
        j0 = j;
      }
      else v[i][j] = s[p] - '0';
    }
    return {move(v), i0, j0};
  };

  ll big = 1e18;
  ll ans = big;
  my_umap<string, ll> dist_fst;
  auto f = [&](auto& init, ll mode) -> void {
    my_umap<string, ll> dist;
    string s0 = enc(init);
    dist[s0] = 0;
    queue<string> que;
    que.push(s0);
    while (not que.empty()) {
      string s = que.front(); que.pop();
      ll dist1 = dist[s];
      if (mode == 1) {
        auto it = dist_fst.find(s);
        if (it != dist_fst.end()) ans = min(ans, dist1 + it->second);
      }
      if (dist1 + 1 <= lim) {
        auto [v, i, j] = dec(s);
        for (auto [di, dj] : dirs) {
          ll ii = i + di;
          ll jj = j + dj;
          if (on_board(ii, jj)) {
            swap(v[i][j], v[ii][jj]);
            string s2 = enc(v);
            auto [it, b] = dist.try_emplace(s2, dist1 + 1);
            if (b) {
              que.push(s2);
            }
            swap(v[i][j], v[ii][jj]);
          }
        }
      }
    }
    if (mode == 0) dist_fst = move(dist);
  };

  f(S, 0);
  f(T, 1);
  cout << (ans == big ? -1 : ans) << endl;

  return 0;
}

