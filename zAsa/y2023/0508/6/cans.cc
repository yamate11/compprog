#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  ll nalph = 26;
  vector vec(nalph, 0LL);
  // REP(i, 0, K) vec[S[i] - 'a']++;
  vector<vector<ll>> tbl;
  tbl.push_back(vec);
  REP(i, 0, N - K) {
    vec[S[i] - 'a']--;
    vec[S[i + K] - 'a']++;
    tbl.push_back(vec);
  }
  set<vector<ll>> ss;
  REP(i, K, N - K + 1) {
    ss.insert(tbl[i - K]);
    if (ss.find(tbl[i]) != ss.end()) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

