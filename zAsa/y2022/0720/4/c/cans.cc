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

  string S1, T; cin >> S1 >> T;
  string S;

  auto match = [&](ll i) -> bool {
    if (SIZE(S1) - i < SIZE(T)) return false;
    REP(j, SIZE(T)) {
      char c = S1[i + j];
      if (c != '?' and c != T[j]) return false;
    }
    return true;
  };

  REP2R(i, SIZE(S1) - 1, 0) {
    if (match(i)) {
      S = S1;
      REP(j, SIZE(S)) if (S[j] == '?') S[j] = 'a';
      REP(j, SIZE(T)) S[i + j] = T[j];
      cout << S << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE\n";

  return 0;
}

