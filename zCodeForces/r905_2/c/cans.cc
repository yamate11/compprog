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

// @@ !! LIM(unordered_map)

// ---- inserted library file unordered_map.cc

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

// ---- end unordered_map.cc

// @@ !! LIM -- end mark --

// using mymap = gp_hash_table<ll, pll, safe_custom_hash>;
// using mymap = gp_hash_table<ll, pll>;
// using mymap = unordered_map<ll, pll>;
using mymap = unordered_map<ll, pll, safe_custom_hash>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    // @InpVec(N, A) [YcMJwOE6]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [YcMJwOE6]
    mymap pos;
    REP(i, 0, N) {
      auto it = pos.find(A[i]);
      if (it == pos.end()) pos[A[i]] = pll(i, i);
      else                 it->second.second = i;
    }
    vector AR(N, 0LL);
    for (auto& [_, p] : pos) AR[p.second] = 1;
    REPrev(i, N - 2, 0) AR[i] += AR[i + 1];
    ll ret = 0;
    for (auto& [_, p] : pos) ret += AR[p.first];
    return ret;

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

