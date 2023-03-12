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

  ll N; cin >> N;
  string S; cin >> S;
  set<pll> ss{{0, 0}};
  ll x = 0, y = 0;
  REP(i, 0, N) {
    if (S[i] == 'R') x += 1;
    else if (S[i] == 'L') x -= 1;
    else if (S[i] == 'U') y += 1;
    else if (S[i] == 'D') y -= 1;
    else assert(0);
    if (ss.find(pll(x, y)) != ss.end()) {
      cout << "Yes\n";
      return 0;
    }
    ss.insert(pll(x, y));
  }
  cout << "No\n";

  return 0;
}

