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

  ll N, A, B;
  cin >> N >> A >> B;
  string S; cin >> S;
  ll passed = 0;
  ll os = 0;
  for (char c : S) {
    bool p = false;
    if (c == 'a' and passed < A + B) {
      p = true;
    }else if (c == 'b' and passed < A + B and os < B) {
      p = true;
      os++;
    }
    if (p) {
      cout << "Yes\n";
      passed++;
    }else {
      cout << "No\n";
    }
  }

  return 0;
}

