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

  ll D, N; cin >> D >> N;
  ll ans = 0;
  for (ll n = 1; true; n++) {
    ll cnt = 0;
    ll x = n;
    while (x % 100 == 0) {
      cnt++;
      x /= 100;
    }
    if (cnt == D) ans++;
    if (ans == N) {
      cout << n << endl;
      return 0;
    }
  }


  return 0;
}

