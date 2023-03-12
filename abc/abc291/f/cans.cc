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
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  const ll big = 1e18;
  vector fromL(N, big);
  vector toR(N, big);
  fromL[0] = 0;
  toR[N-1] = 0;
  REP(i, 0, N) REP(j, 0, M) if (S[i][j] == '1') updMin(fromL[i + j + 1], fromL[i] + 1);
  vector bwd(N, vector<ll>());
  REP(i, 0, N) REP(j, 0, M) if (S[i][j] == '1') bwd[i + j + 1].push_back(i);
  REPrev(i, N-1, 1) for (ll j : bwd[i]) updMin(toR[j], toR[i] + 1);
  REP(k, 1, N-1) {
    ll val = big;
    REP(i, k - M + 1, k) REP(j, k + 1, k + M) {
      if (i < 0 or N <= j) continue;
      if (fromL[i] == big or toR[j] == big) continue;
      if (i + M < j) continue;
      if (S[i][j - i - 1] == '0') continue;
      updMin(val, fromL[i] + toR[j] + 1);
    }
    if (val == big) cout << -1 << " ";
    else cout << val << " ";
  }
  cout << endl;
  return 0;
}

