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

  ll big = 1e18;
  ll th = 1e17;
  string s, t; cin >> s >> t;
  string ss = s + s;
  ll N = ssize(s);
  vector vec(N, vector(26, 0LL));
  {
    vector pos(26, big);
    REPrev(i, 2*N - 1, 0) {
      pos[ss[i] - 'a'] = i;
      if (i < N) {
        REP(c, 0, 26) vec[i][c] = pos[c] - i;
      }
    }
  }
  ll p = 0;
  REP(i, 0, ssize(t)) {
    ll len = vec[p % N][t[i] - 'a'];
    p += len + 1;
    if (p >= th) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << p << endl;

  return 0;
}

