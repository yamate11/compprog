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

struct safe_custom_hash {
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

#define UO_map(T_key, T_value) unordered_map<T_key, T_value, safe_custom_hash>
#define UO_set(T_key) unordered_set<T_key, safe_custom_hash>
#define UO_multiset(T_key) unordered_multiset<T_key, safe_custom_hash>

// ---- end unordered_map.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  
  vector<ll> th(N + 1), putty(N + 1);
  th[0] = 1;
  REP(n, 1, N + 1) th[n] = 1 + th[n - 1] + 1 + th[n - 1] + 1;
  putty[0] = 1;
  REP(n, 1, N + 1) putty[n] = putty[n - 1] + 1 + putty[n - 1];
  

  using mymap = UO_map(ll, ll);
  vector<mymap> tbl(N + 1);
  auto f = [&](auto rF, ll n, ll x) -> ll {
    if (x == 0) return 0;
    if (n == 0) return 1;
    auto [it, b] = tbl[n].try_emplace(x, 0LL);
    ll& p = it->second;
    if (b) {
      auto recurse = [&](ll m) -> void {
        if (x >= th[m]) {
          p += putty[m];
          x -= th[m];
        }else {
          p += rF(rF, m, x);
          x = 0;
        }
      };
      
      if (x >= 1) x--;
      recurse(n - 1);
      recurse(0);
      recurse(n - 1);
    }
    return p;
  };

  cout << f(f, N, X) << endl;

  return 0;
}

