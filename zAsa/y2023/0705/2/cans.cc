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

  string t; cin >> t;
  vector<ll> A(4);
  REP(i, 0, 4) A[i] = t[i] - '0';


  REP(x, 0, 8) {
    ll s = A[0];
    REP(i, 0, 3) {
      if (x >> i & 1) {
        s -= A[i + 1];
      }else {
        s += A[i + 1];
      }
    }
    if (s == 7) {
      cout << A[0];
      REP(i, 0, 3) {
        if (x >> i & 1) cout << "-";
        else cout << "+";
        cout << A[i + 1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }

  return 0;
}

