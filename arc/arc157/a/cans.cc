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

  ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  if (b == 0 and c == 0) {
    if (a == 0 or d == 0) {
      cout << "Yes\n";
    }else {
      cout << "No\n";
    }
    return 0;
  }

  if (b == c or b == c + 1 or c == b + 1) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

