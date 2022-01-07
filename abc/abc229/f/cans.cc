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
  vector<ll> A(N), B(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  vector tbl_init(2, vector(2, 0LL));
  const ll UP = 0, DN = 1;
  auto tbl = tbl_init;
  REP(i, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    if (i == 0) {
      tbl[UP][UP] = B[N-1] + A[0];
      tbl[DN][UP] = A[0];
      tbl[UP][DN] = 0;
      tbl[DN][DN] = B[N-1];
    }else {
      REP(t, 2) {
        tbl[t][UP] = min(prev[t][UP] + B[i-1] + A[i], prev[t][DN] + A[i]);
        tbl[t][DN] = min(prev[t][UP],                 prev[t][DN] + B[i-1]);
      }
    }
  }
  ll ans = min(tbl[UP][UP], tbl[DN][DN]);
  cout << ans << endl;

  return 0;
}

