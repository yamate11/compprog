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
  ll hi = 0, mi = 0, lo = 0;
  REP(i, 0, N) {
    if (S[i] == 'o') hi++;
    else if (S[i] == '-') mi++;
    else if (S[i] == 'x') lo++;
    else assert(0);
  }
  if (hi > 0 and lo == 0) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

