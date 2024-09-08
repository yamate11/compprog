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
  vector A(N, vector(N, 0LL));
  REP(i, 0, N) {
    REP(j, 0, i + 1) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  ll cur = 0;
  REP(i, 0, N) {
    if (cur <= i) cur = A[i][cur];
    else cur = A[cur][i];
  }
  cout << cur  + 1 << endl;
  

  return 0;
}

