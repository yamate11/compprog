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

  // ll x = 1000000000000000000; // x = 10 ^ 18
  ll y = 1000000000; // y = 10 ^ 9
  REP(i, y, y + 10000) {
    double d = (double)(i * i);
    ll z = (ll)d;
    double e = sqrt(i * i);
    ll w1 = llround(floor(e));
    ll w2 = llround(ceil(e));
    cout << i * i << " " << z << "    " << i << " " << w1 << " " << w2 << "\n";
  }


  return 0;
}

