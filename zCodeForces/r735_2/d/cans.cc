#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> string {
    ll n; cin >> n;
    if (n == 1) return "a";
    if (n == 2) return "ab";
    if (n % 2 == 0) {
      string x(n / 2 - 1, 'a');
      return x + 'b' + x + 'a';
    }else {
      string x((n - 1) / 2 - 1, 'a');
      return x + 'b' + x + 'a' + 'c';
    }

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

