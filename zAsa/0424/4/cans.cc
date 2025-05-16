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
  vector<string> A(N);
  REP(i, 0, N) cin >> A[i];
  vector<string> B(N, string(N, ' '));
  auto op = [&](ll x, ll y) -> void {
    B[y][-x + N - 1] = A[x][y];
  };
  auto op2 = [&](ll x, ll y) -> void {
    A[x][y] = B[x][y];
  };

  REP(p, 0, N/2) {
    REP(k, 0, (p + 1) % 4) {
      REP(i, p, N - p) {
        op(p, i);
        op(N - 1 - p, i);
        op(i, p);
        op(i, N - 1 - p);
      }
      REP(i, p, N - p) {
        op2(p, i);
        op2(N - 1 - p, i);
        op2(i, p);
        op2(i, N - 1 - p);
      }
    }
  }

  REPOUT(i, 0, N, A[i], "\n");
  

  return 0;
}

