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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  string S; cin >> S;
  vector rec(N, vector<ll>(26, 0LL));
  set<vector<ll>> sv;
  vector cur(26, 0LL);
  REP(i, 0, N) {
    cur[S[i] - 'a']++;
    if (i - K >= 0) cur[S[i - K] - 'a']--;
    rec[i] = cur;
    if (i - K >= 0) sv.insert(rec[i - K]);
    if (sv.find(cur) != sv.end()) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

