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

  string S; cin >> S;
  string T = "@@";
  REP(i, 0, SIZE(S)) {
    T += S[i];
    ll n = SIZE(T);
    if (T[n - 3] == 'A' and T[n - 2] == 'B' and T[n - 1] == 'C') {
      T.pop_back();
      T.pop_back();
      T.pop_back();
    }
  }
  cout << T.substr(2) << endl;
  return 0;
}

