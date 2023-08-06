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
  ll M = 2 * N;
  cout << M << endl;
  vector<ll> X;
  while (N > 0) {
    if (N >= 4) {
      X.push_back(4);
      N -= 4;
    }else {
      X.push_back(N);
      N = 0;
    }
  }
  reverse(ALL(X));
  REP(i, 0, SIZE(X)) cout << X[i];
  cout << endl;

  return 0;
}

