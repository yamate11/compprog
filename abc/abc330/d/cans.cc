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
  vector<string> vec(N);
  REP(i, 0, N) cin >> vec[i];
  vector R(N, 0LL);
  vector C(N, 0LL);
  REP(i, 0, N) {
    R[i] = 0;
    REP(j, 0, N) if (vec[i][j] == 'o') R[i]++;
  }
  REP(j, 0, N) {
    C[j] = 0;
    REP(i, 0, N) if (vec[i][j] == 'o') C[j]++;
  }
  ll ans = 0;
  REP(i, 0, N) REP(j, 0, N) {
    if (vec[i][j] == 'o') ans += (R[i] - 1) * (C[j] - 1);
  }
  cout << ans << endl;
  return 0;
}

