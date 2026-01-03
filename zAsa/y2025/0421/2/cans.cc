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

  ll n, a, b; cin >> n >> a >> b; a--; b--;
  ll ans;
  if ((a - b) % 2 == 0) {
    ans = abs(a - b) / 2;
  }else {
    if (a > b) swap(a, b);
    ll x = min(a, n - 1 - b);
    ans = x + 1 + (b - a - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}

