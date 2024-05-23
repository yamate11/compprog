#include <bits/stdc++.h>
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

  vector v(10, vector(10, 0.0));
  v[0][0] = 1.0;
  REP(k, 1, 10) {
    REP(c, 0, 10) {
      double x = 0.0;
      REP(d, 0, c + 1) x += v[d][k - 1];
      v[c][k] = x;
    }
  }
  REP(c, 0, 10) {
    cout << c << endl;
    REP(k, 0, 10) cout << v[c][k] << " ";
    cout << endl;
  }


  return 0;
}

