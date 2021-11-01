#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

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

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) { cin >> A[i]; A[i]--; }
  ll big = 1e9;
  vector<ll> V(1LL << K, big);
  REP(i, N) {
    ll t = A[i];
    ll mask = (1LL << t) - 1;
    V[0] = - K * i;
    REP(x, 1LL << K) {
      if ((x >> t) & 1) continue;
      ll pre = __builtin_popcountll(x & mask);
      updMin(V[x | (1LL << t)], V[x] + i - pre);
    }
  }
  cout << V[(1LL << K) - 1] << endl;

  return 0;
}

