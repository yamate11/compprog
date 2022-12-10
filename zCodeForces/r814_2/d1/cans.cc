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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [c3kAEc4K]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [c3kAEc4K]
    vector<ll> B(N + 1);
    REP(i, 0, N) B[i + 1] = B[i] ^ A[i];
    map<ll, ll> mp;
    vector<ll> nxt(N + 1);
    REPrev(i, N, 0) {
      auto it = mp.find(B[i]);
      if (it == mp.end()) nxt[i] = -1;
      else nxt[i] = it->second;
      mp[B[i]] = i;
    }
    ll big = 1e18;
    vector<ll> tbl(N + 1, big);
    tbl[0] = 0;
    REP(i, 0, N) {
      updMin(tbl[i + 1], tbl[i] + 1);
      ll j = nxt[i];
      if (j >= 0) {
        updMin(tbl[j], tbl[i] + (j - i) - 1);
      }
    }
    cout << tbl[N] << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

