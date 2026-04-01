#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  ll N, X; cin >> N >> X;
  string S; cin >> S;
  string T;
  for (char c : S) {
    if (T.empty()) T += c;
    else {
      if (c == 'U' and (T.back() == 'L' or T.back() == 'R')) T.pop_back();
      else T += c;
    }
  }
  for (char c : T) {
    if (c == 'U') X = X / 2;
    else if (c == 'L') X = 2 * X;
    else if (c == 'R') X = 2 * X + 1;
    else assert(0);
  }
  cout << X << endl;
  return 0;
}

