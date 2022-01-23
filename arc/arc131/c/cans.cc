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
  vector<ll> A(N);
  ll s = 0;
  REP(i, N) {
    cin >> A[i];
    s ^= A[i];
  }
  REP(i, N) {
    if (A[i] == s) {
      cout << "Win\n";
      return 0;
    }
  }
  if (N % 2 == 0) cout << "Lose\n";
  else cout << "Win\n";


  return 0;
}

