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
  }
  vector A(N, vector<ll>(N));

  ll e = 1;
  auto f = [&](ll i) {
    REP(j, 0, N) A[i][j] = e++;
  };

  {
    ll i = 0;
    for (; i < N; i += 2) f(i);
    i = 1;
    for (; i < N; i += 2) f(i);
  }

  swap(A[0][1], A[0][N-1]);
  swap(A[N-1][1], A[N-1][N-1]);

  REP(i, 0, N) {
    REPOUT(j, 0, N, A[i][j], " ");
  }
  return 0;
}

