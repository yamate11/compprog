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
  vector X(N, vector(N, 0LL));
  ll seq = 1;
  auto f = [&](ll i, bool b) -> void {
    if (not b) {
      X[i][0] = seq++;
      X[i][N - 1] = seq++;
      REP(j, 1, N - 1) X[i][j] = seq++;
    }else {
      REP(j, 1, N - 1) X[i][j] = seq++;
      X[i][0] = seq++;
      X[i][N - 1] = seq++;
    }
  };
  REP(i, 0, N) {
    if (i % 2 == 0) {
      f(i, false);
    }
  }
  REP(i, 0, N)
    if (i % 2 != 0) {
      if (i == N - 1) f(i, true);
      else f(i, false);
    }
  REP(i, 0, N) {
    REPOUT(j, 0, N, X[i][j], " ");
  }

  return 0;
}

