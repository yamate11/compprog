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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [wdnh8sNd]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wdnh8sNd]

  vector<ll> vec(N + 1, 0LL);
  REP(i, 0, M) vec[A[i]]++;
  set<ll> ss;
  REP(i, 0, N + 1) if (vec[i] == 0) ss.insert(i);

  ll i = M;
  ll ans = 1e18;
  while (true) {
    updMin(ans, *ss.begin());
    if (i == N) break;
    ll a = A[i];
    if (vec[a] == 0) ss.erase(a);
    vec[a]++;
    a = A[i - M];
    if (vec[a] == 1) ss.insert(a);
    vec[a]--;

    i++;
  }
  cout << ans << endl;

  return 0;
}

