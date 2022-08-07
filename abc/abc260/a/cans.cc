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

  string S; cin >> S;
  if (S[0] == S[1] and S[1] == S[2]) {
    cout << -1 << endl;
    return 0;
  }
  if (S[0] != S[1] and S[0] != S[2]) {
    cout << S[0] << endl;
    return 0;
  }
  if (S[1] != S[0] and S[1] != S[2]) {
    cout << S[1] << endl;
    return 0;
  }
  if (S[2] != S[0] and S[2] != S[1]) {
    cout << S[2] << endl;
    return 0;
  }

  return 0;
}

