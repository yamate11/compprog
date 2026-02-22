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

  ll a, b, k; cin >> a >> b >> k;
  REP(i, 0, k) {
    if (i % 2 == 0) {
      if (a % 2 != 0) a--;
      ll x = a / 2;
      a -= x;
      b += x;
    }else {
      if (b % 2 != 0) b--;
      ll x = b / 2;
      a += x;
      b -= x;
    }
  }
  cout << a << " " << b << "\n";
  return 0;
}

