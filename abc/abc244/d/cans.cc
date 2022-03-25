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

  auto solve = [&]() -> bool {
    vector<char> S(3), T(3);
    REP(i, 3) cin >> S[i];
    REP(i, 3) cin >> T[i];
    if (S[0] == T[0] and S[1] == T[1] and S[2] == T[2]) return true;
    if (S[0] == T[1] and S[1] == T[2] and S[2] == T[0]) return true;
    if (S[0] == T[2] and S[1] == T[0] and S[2] == T[1]) return true;
    return false;
  };
  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

