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
  if (N == 2) {
    cout << "1 3\n4 2\n";
    return 0;
  }else if (N == 3) {
    cout << "1 5 2\n6 9 7\n3 8 4\n";
    return 0;
  }


  vector X(N, vector(N, 0LL));
  ll hE, hO;
  if (N % 2 == 0) {
    hE = hO = N / 2;
  }else {
    hO = N / 2;
    hE = N - hO;
  }
  auto f = [&](ll r, ll st) -> void {
    REP(j, 0, N) X[r][j] = st * N + j;
  };
  REP(i, 0, hE) f(2 * i, i);
  REP(i, 0, hO) f(2 * i + 1, hE + i);
  auto g = [&](ll r, ll c, ll dc, ll dr) {
    if ((X[r][c] < X[r][c + dc]) != (X[r][c] < X[r + dr][c])) {
      swap(X[r][c], X[r][c + dc]);
    }
  };
  g(0,     0,      1, 1);
  g(0,     N - 1, -1, 1);
  g(N - 1, 0,      1, -1);
  g(N - 1, N - 1, -1, -1);

  REP(r, 0, N) {
    REPOUT(c, 0, N, X[r][c] + 1, " ");
  }

  return 0;
}

