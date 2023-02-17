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

  string s; cin >> s;
  vector A(4, 0LL);
  REP(i, 0, 4) A[i] = s[i] - '0';
  REP(x, 0, 8) {
    ll y = A[0];
    REP(i, 0, 3) {
      if (x >> i & 1) y += A[i + 1];
      else y -= A[i + 1];
    }
    if (y == 7) {
      cout << A[0];
      REP(i, 0, 3) {
        if (x >> i & 1) cout << '+';
        else cout << '-';
        cout << A[i + 1];
      }
      cout << "=7" << endl;
      return 0;
    }

  }
  

  return 0;
}

