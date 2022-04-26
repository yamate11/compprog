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
  set<char> ss;
  bool lower = false;
  bool upper = false;
  for (char c : S) {
    if (ss.find(c) != ss.end()) {
      cout << "No\n";
      return 0;
    }
    ss.insert(c);
    if ('a' <= c and c <= 'z') lower = true;
    if ('A' <= c and c <= 'Z') upper = true;
  }
  if (lower and upper) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

