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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> A(4);
  REP(i, 0, 4) cin >> A[i];
  REP(x, 0, 1LL << 4) {
    ll s = 0, t = 0;
    REP(p, 0, 4) {
      if (x >> p & 1) s += A[p];
      else t += A[p];
    }
    if (s == t) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;

  return 0;
}

