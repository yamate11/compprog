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
  set<string> said;
  string v;
  REP(i, N) {
    string w; cin >> w;
    if (i > 0) {
      if (said.find(w) != said.end() or w[0] != v[SIZE(v) - 1]) {
        cout << "No\n";
        return 0;
      }
    }
    said.insert(w);
    v = w;
  }
  cout << "Yes\n";

  return 0;
}

