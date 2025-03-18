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

  ll x, a, d, n; cin >> x >> a >> d >> n;
  ll fst = a;
  ll lst = a + (n - 1) * d;
  if (fst > lst) swap(fst, lst);
  ll ans;
  if (x <= fst) ans = fst - x;
  else if (lst <= x) ans = x - lst;
  else {
    ll r = (x - fst) % abs(d);
    ans = min(r, abs(d) - r);
  }
  cout << ans << endl;

  return 0;
}

