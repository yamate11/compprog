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

  ll N; cin >> N;
  // @InpVec(N, V) [IWuvrd1j]
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [IWuvrd1j]

  ll lim = *max_element(ALL(V));

  vector ecnt(lim + 1, 0);
  vector ocnt(lim + 1, 0);
  REP(i, 0, N) {
    if (i % 2 == 0) ecnt[V[i]]++;
    else ocnt[V[i]]++;
  }
  vector eee(lim + 1, pll(0, 0));
  vector ooo(lim + 1, pll(0, 0));
  REP(i, 0, lim + 1) {
    eee[i] = pll(ecnt[i], i);
    ooo[i] = pll(ocnt[i], i);
  }
  sort(ALL(eee), greater<pll>());
  sort(ALL(ooo), greater<pll>());
  ll ans = 1e18;
  REP(i, 0, 2) REP(j, 0, 2) {
    auto [c0, x0] = eee[i];
    auto [c1, x1] = ooo[j];
    if (x0 == x1) continue;
    updMin(ans, N - (c0 + c1));
  }
  cout << ans << endl;

  return 0;
}

