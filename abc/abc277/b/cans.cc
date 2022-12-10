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

  ll N; cin >> N;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  set<string> ss;
  REP(i, 0, N) {
    char c = S[i][0];
    if (c != 'H' and c != 'D' and c != 'C' and c != 'S') {
      cout << "No\n";
      return 0;
    }
    c = S[i][1];
    if (c != 'A' and c != 'T' and c != 'J' and c != 'Q' and c != 'K'
        and (not ('2' <= c and c <= '9'))) {
      cout << "No\n";
      return 0;
    }
    if (ss.find(S[i]) != ss.end()) {
      cout << "No\n";
      return 0;
    }
    ss.insert(S[i]);
  }
  cout << "Yes\n";

  return 0;
}

