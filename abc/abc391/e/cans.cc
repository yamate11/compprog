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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string s; cin >> s;
  ll M = ssize(s);
  vector<int> A(M);
  REP(i, 0, M) A[i] = s[i] - '0';
  vector B(N + 1, vector<int>());
  B[0] = A;
  REP(k, 0, N) {
    B[k + 1] = vector<int>(ssize(B[k]) / 3);
    REP(i, 0, ssize(B[k]) / 3) {
      ll t = B[k][3*i] + B[k][3*i + 1] + B[k][3*i + 2];
      if (t <= 1) B[k + 1][i] = 0;
      else B[k + 1][i] = 1;
    }
  }
  int orig = B[N][0];
  if (orig == 1) {
    REP(k, 0, N + 1) REP(i, 0, ssize(B[k])) B[k][i] = 1 - B[k][i];
    orig = 0;
  }
  vector C(N + 1, vector<int>());
  REP(k, 0, N + 1) C[k] = vector<int>(ssize(B[k]));
  REP(i, 0, ssize(B[0])) {
    if (B[0][i] == 0) C[0][i] = 1;
    else              C[0][i] = 0;
  }
  REP(k, 1, N + 1) {
    REP(i, 0, ssize(B[k])) {
      if (B[k][i] == 1) C[k][i] = 0;
      else {
        vector<int> v;
        REP(j, 0, 3) v.push_back(C[k - 1][3 * i + j]);
        sort(ALL(v));
        C[k][i] = v[0] + v[1];
      }
    }
  }
  cout << C[N][0] << endl;
  


  return 0;
}

