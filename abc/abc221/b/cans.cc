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

  string S, T; cin >> S >> T;
  ll cnt = 0;
  ll d1 = -1;
  ll d2 = -1;
  for (ll i = 0; i < SIZE(S); i++) {
    if (S[i] != T[i]) {
      if (cnt == 0) d1 = i;
      else d2 = i;
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << "Yes\n";
  }else if (cnt != 2) {
    cout << "No\n";
  }else if (abs(d1 - d2) == 1 && S[d2] == T[d1] && S[d1] == T[d2]) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

