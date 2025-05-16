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

// ---- end unordered_map.cc

// @@ !! LIM -- end mark --

using mymap = unordered_map<ll, ll, safe_custom_hash>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e18;

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    // @InpVec(N, A) [6i7hIXNn]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [6i7hIXNn]
    // @InpVec(N, B) [NQY4UXFz]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [NQY4UXFz]

    mymap mpA, mpB;
    for (ll b : B) mpB[b]++;
    ll lo = *max_element(ALL(B)) + 1;
    for (ll a : A) {
      if (a >= lo) {
        mpA[a]++;
      }else {
        auto it = mpB.find(a);
        if (it == mpB.end()) return -1;
        if (--it->second == 0) mpB.erase(it);
      }
    }
    if (mpA.empty()) return lo;
    ll hi = big;
    ll maxA = 0;
    for (auto [a, c] : mpA) {
      hi = min(hi, a);
      maxA = max(maxA, a);
    }
    vector<bool> vec(hi + 1, true);
    vector<ll> cands;
    REP(i, lo, hi + 1) {
      if (vec[i]) {
        cands.push_back(i);
        ll j = i + i;
        while (j <= hi) {
          vec[j] = false;
          j += i;
        }
      }
    }
    for (auto [b, c] : mpB) {
      auto prev = move(cands);
      cands = vector<ll>();
      for (ll k : prev) {
        ll cnt = 0;
        for (ll t = k + b; t <= maxA; t += k) {
          auto it = mpA.find(t);
          if (it != mpA.end()) cnt += it->second;
        }
        if (cnt == c) cands.push_back(k);
      }
      if (cands.empty()) return -1;
    }
    return cands[0];
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) {
    cout << solve() << "\n";
  }

  return 0;
}

