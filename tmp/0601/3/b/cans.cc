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

const vector<string> postfix = {"o", "k", "u", "ch"};

string solve(string s) {
  if (s == "") return "YES";
  size_t sz = s.size();
  for (string p : postfix) {
    ll psz = p.size();
    if (sz >= psz and s.substr(sz - psz) == p) return solve(s.substr(0, sz - psz));
  }
  return false;
};

int main() {
  string X; cin >> X;
  cout << solve(X) << endl;
  return 0;
}

