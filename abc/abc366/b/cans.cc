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
  // @InpVec(N, S, type=string) [4UZlVq9t]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [4UZlVq9t]

  ll M = 0;
  REP(i, 0, N) {
    M = max(M, (ll)ssize(S[i]));
  }
  vector<string> T(M, string(N, ' '));
  REP(i, 0, N) {
    REP(j, 0, ssize(S[i])) {
      T[j][N - 1 - i] = S[i][j];
    }
  }
  REP(i, 0, M) {
    bool seen = false;
    ll len = N;
    REPrev(j, N - 1, 0) {
      if (T[i][j] != ' ') {
        seen = true;
      }else {
        if (not seen) {
          len = j;
        }else {
          T[i][j] = '*';
        }
      }
    }
    T[i] = T[i].substr(0, len);
  }
  REP(i, 0, M) {
    cout << T[i] << "\n";
  }
  


  return 0;
}

