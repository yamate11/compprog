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
  REP(i, N -1) {
    cin >> A[i] >> B[i];
  }
  ll com = -1;
  if (A[0] == A[1]) com = A[0];
  else if (A[0] == B[1]) com = A[0];
  else if (B[0] == A[1]) com = B[0];
  else if (B[0] == B[1]) com = B[0];
  else {
    cout << "No\n";
    return 0;
  }
  REP(i, N - 1) {
    if (A[i] != com and B[i] != com) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";


  return 0;
}

