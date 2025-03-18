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

  ll N = 10;
  vector r(N, false);
  vector c(N, false);
  REP(i, 0, N) {
    string s; cin >> s;
    REP(j, 0, N) {
      if (s[j] == '#') r[i] = c[j] = true;
    }
  }
  ll A = 0, B = 0, C = 0, D = 0;
  REP(i, 0, N) {
    if (r[i]) {
      A = i;
      break;
    }
  }
  REP(i, 0, N) {
    if (r[i]) B = i;
  }
  REP(i, 0, N) {
    if (c[i]) {
      C = i;
      break;
    }
  }
  REP(i, 0, N) {
    if (c[i]) D = i;
  }
  cout << A + 1 << " " << B + 1 << "\n" << C + 1 << " " << D + 1 << "\n";

  return 0;
}

