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

  ll N, S; cin >> N >> S;
  // @InpMVec(N, (W, V, C)) [otTHthzM]
  auto W = vector(N, ll());
  auto V = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; W[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [otTHthzM]
  vector<ll> V0;
  vector<ll> W0;
  REP(i, 0, N) {
    ll t = 0;
    for (ll d = 1; true; d *= 2) {
      if (t + d <= C[i]) {
        W0.push_back(W[i] * d);
        V0.push_back(V[i] * d);
        t += d;
      }else if (t == C[i]) {
        break;
      }else {
        W0.push_back(W[i] * (C[i] - t));
        V0.push_back(V[i] * (C[i] - t));
        break;
      }
    }
  }
  ll sz = ssize(V0);
  vector<ll> tbl(S + 1, -1LL);
  tbl[0] = 0;
  REP(i, 0, sz) {
    REPrev(j, S, 0) if (tbl[j] >= 0 and j + W0[i] <= S) {
      updMax(tbl[j + W0[i]], tbl[j] + V0[i]);
    }
  }
  if (tbl[S] < 0) {
    cout << -1 << endl;
  }else {
    cout << tbl[S] << endl;
  }

  return 0;
}

