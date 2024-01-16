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

  ll N; cin >> N;
  // @InpMVec(N, (A, T)) [cm4FS6Tj]
  auto A = vector(N, ll());
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
  }
  // @End [cm4FS6Tj]
  ll Q; cin >> Q;
  // @InpVec(Q, X) [Cm1xSryG]
  auto X = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; X[i] = v; }
  // @End [Cm1xSryG]
  
  ll lim = 1e9;
  ll L = -lim, R = lim, vL = -lim, vR = lim;
  REP(i, 0, N) {
    if (T[i] == 1) {
      vL += A[i];
      vR += A[i];
    }else if (T[i] == 2) {
      if (A[i] >= vR) {
        L = R = 0;
        vL = vR = A[i];
      }else if (A[i] <= vL) {
      }else {
        ll d = A[i] - vL;
        vL += d;
        L += d;
      }
    }else if (T[i] == 3) {
      if (A[i] >= vR) {
      }else if (A[i] <= vL) {
        L = R = 0;
        vL = vR = A[i];
      }else {
        ll d = vR - A[i];
        vR -= d;
        R -= d;
      }
    }else assert(0);
  }
  REP(i, 0, Q) {
    if (X[i] <= L) {
      cout << vL << "\n";
    }else if (R <= X[i]) {
      cout << vR << "\n";
    }else {
      ll d = X[i] - L;
      cout << vL + d << "\n";
    }
  }

  return 0;
}

