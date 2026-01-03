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

  ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
  // @InpVec(X, A) [I0Kw4aRJ]
  auto A = vector(X, ll());
  for (int i = 0; i < X; i++) { ll v; cin >> v; A[i] = v; }
  // @End [I0Kw4aRJ]
  // @InpVec(Y, B) [S3ZPob65]
  auto B = vector(Y, ll());
  for (int i = 0; i < Y; i++) { ll v; cin >> v; B[i] = v; }
  // @End [S3ZPob65]
  // @InpVec(Z, C) [bNfLl6mJ]
  auto C = vector(Z, ll());
  for (int i = 0; i < Z; i++) { ll v; cin >> v; C[i] = v; }
  // @End [bNfLl6mJ]

  sort(ALL(A), greater<ll>());
  sort(ALL(B), greater<ll>());
  sort(ALL(C), greater<ll>());

  auto enc = [&](ll i, ll j, ll k) -> ll { return i * 1000 * 1000 + j * 1000 + k; };
  using sta = tuple<ll, ll, ll, ll>;
  priority_queue<sta> pque;
  pque.emplace(A[0] + B[0] + C[0], 0, 0, 0);
  my_uset<ll> us;
  us.emplace(enc(0, 0, 0));
  ll cnt = 0;

  auto f = [&](ll i, ll j, ll k) -> void {
    if (us.contains(enc(i, j, k))) return;
    us.emplace(enc(i, j, k));
    pque.emplace(A[i] + B[j] + C[k], i, j, k);
  };

  while (true) {
    auto [v, i, j, k] = pque.top(); pque.pop();
    cout << v << "\n";
    cnt++;
    if (cnt == K) break;

    if (i + 1 < X) f(i + 1, j, k);
    if (j + 1 < Y) f(i, j + 1, k);
    if (k + 1 < Z) f(i, j, k + 1);
  }


  return 0;
}

