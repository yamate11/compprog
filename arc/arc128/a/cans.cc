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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<double> A(N); REP(i, N) cin >> A[i];
  vector<double> G(N), S(N);
  vector<ll> GC(N), SC(N);
  G[N-1] = 0.0;
  S[N-1] = -log(A[N-1]);
  GC[N-1] = 0;
  SC[N-1] = 1;
  REP2R(i, N-2, 0) {
    if (G[i + 1] > log(A[i]) + S[i + 1]) {
      G[i] = G[i + 1];
      GC[i] = 0;
    }else {
      G[i] = log(A[i]) + S[i + 1];
      GC[i] = 1;
    }
    if (G[i + 1] - log(A[i]) > S[i + 1]) {
      S[i] = G[i + 1] - log(A[i]);
      SC[i] = 1;
    }else {
      S[i] = S[i + 1];
      SC[i] = 0;
    }
  }
  ll tp = 0;
  REP(i, N) {
    if (tp == 0) {
      cout << GC[i] << " ";
      if (GC[i] == 0) tp = 0;
      else tp = 1;
    }else {
      cout << SC[i] << " ";
      if (SC[i] == 0) tp = 1;
      else tp = 0;
    }
  }
  cout << endl;

  return 0;
}

