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

  // @InpVec(10, S, type=string) [QUcZz18R]
  auto S = vector(10, string());
  for (int i = 0; i < 10; i++) { string v; cin >> v; S[i] = v; }
  // @End [QUcZz18R]

  vector<bool> X(12, false), Y(12, false);
  REP(i, 0, 10) REP(j, 0, 10) {
    if (S[i][j] == '#') {
      X[i + 1] = true;
      Y[j + 1] = true;
    }
  }
  ll a, b, c, d;
  REP(i, 0, 11) {
    if (not X[i] and X[i + 1]) a = i + 1;
    if (X[i] and not X[i + 1]) b = i;
    if (not Y[i] and Y[i + 1]) c = i + 1;
    if (Y[i] and not Y[i + 1]) d = i;
  }
  cout << a << " " << b << endl;
  cout << c << " " << d << endl;

  return 0;
}

