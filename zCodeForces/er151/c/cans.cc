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

  auto solve = [&]() -> void {
    string S; cin >> S;
    ll N = SIZE(S);
    ll M; cin >> M;
    string L, R; cin >> L >> R;
    vector<ll> tmp(10, N);
    vector rpos(N, vector(10, 0LL));
    REPrev(i, N - 1, 0) {
      tmp[S[i] - '0'] = i;
      REP(k, 0, 10) {
        rpos[i][k] = tmp[k];
      }
    }
    ll p = 0;
    REP(i, 0, M) {
      if (p >= N) {
        cout << "YES\n";
        return;
      }
      ll c = -1;
      REP(k, L[i] - '0', R[i] - '0' + 1) {
        updMax(c, rpos[p][k] + 1);
      }
      if (c > N) {
        cout << "YES\n";
        return ;
      }
      p = c;
    }
    cout << "NO\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

