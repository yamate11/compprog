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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<double> G(N + 1), S(N + 1);
  G[0] = 1.0;
  S[0] = 0.0;
  REP(i, N) {
    G[i + 1] = max(G[i], S[i] / double(A[i]));
    S[i + 1] = max(S[i], G[i] * double(A[i]));
  }
  ll ctype = 0;
  vector<ll> ans(N);
  REP2R(i, N-1, 0) {
    double diffG, diffS;
    if (ctype == 0) { // gold
      diffG = abs(G[i+1] - G[i]);
      diffS = abs(G[i+1] - S[i] / double(A[i]));
    }else {
      diffG = abs(S[i+1] - G[i] * double(A[i]));
      diffS = abs(S[i+1] - S[i]);
    }
    ll ntype = diffG < diffS ? 0 : 1;
    ans[i] = ntype == ctype ? 0 : 1;
    ctype = ntype;
  }
  for (ll c : ans) cout << c << " ";
  cout << endl;

  return 0;
}

