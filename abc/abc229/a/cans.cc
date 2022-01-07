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
    string s1, s2; cin >> s1 >> s2;
    ll cnt = 0;
    if (s1[0] == '.') cnt++;
    if (s1[1] == '.') cnt++;
    if (s2[0] == '.') cnt++;
    if (s2[1] == '.') cnt++;
    if (cnt <= 1) return true;
    if (s1[0] == '#' and s2[1] == '#') return false;
    if (s1[1] == '#' and s2[0] == '#') return false;
    return true;
  };
  
  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

