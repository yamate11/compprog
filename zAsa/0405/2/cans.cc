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

  auto f = [&](ll i) -> bool {
    ll k = -1;
    while (i > 0) {
      ll z = i % 10;
      if (k >= 0 and k != z) return false;
      k = z;
      i = i / 10;
    }
    return true;
  };

  ll N; cin >> N;
  ll cnt = 0;
  for (ll i = 1; true; i++) {
    if (f(i)) cnt++;
    if (cnt == N) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

