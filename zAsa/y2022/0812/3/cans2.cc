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
    string S; cin >> S;
    string T = "AKIHABARA";
    ll p = 0;
    REP(q, SIZE(T)) {
      if (p < SIZE(S) and S[p] == T[q]) p++;
      else if (T[q] != 'A') return false;
    }
    return true;
  };
  cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

