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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, A; cin >> N >> A;
  // @InpMVec(N, (W, X, V)) [Wbq8TXTb]
  auto W = vector(N, ll());
  auto X = vector(N, ll());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; W[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
    ll v3; cin >> v3; V[i] = v3;
  }
  // @End [Wbq8TXTb]
  REP(i, 0, N) REP(j, 0, N) {
    if (i == j) continue;
    if (X[i] <= X[j] and X[j] <= X[i] + A) ev[i].reg(0, IN);
    if (V[i] != V[j]) {
      double t = (double)(X[j] - X[i]) / (V[i] - V[j]);
      if (0 < t) {
        if (X[i] < X[j]) ev[i].reg(t, OUT);
        else if (X[j] < X[i]) ev[i].reg(t, IN);
      }
      if (X[i] + A < X[j]) {
        t = (double)(X[j] - (X[i] + A)) / (V[i] - V[j]);
        if (0 < t) ev[i].reg(t, IN);
      }
      if (X[j] < X[i] + A) {
        t = (double)(X[i] + A - X[j]) / (V[j] - V[i]);
        if (0 < t) ev[i].reg(t, OUT);
      }

    }


    if (V[i] < V[j]) {
      
    }else if (V[j] < V[i]) {
    }else if (V[i] == V[j]) {
    }else assert(0);
  }
  

  return 0;
}

