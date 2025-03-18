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

  vector<ll> vec(3);
  REP(i, 0, 3) cin >> vec[i];
  sort(ALL(vec));
  ll ans = 0;
  ll x0 = (vec[2] - vec[0]) / 2;
  ll y0 = (vec[2] - vec[0]) % 2;
  ll x1 = (vec[2] - vec[1]) / 2;
  ll y1 = (vec[2] - vec[1]) % 2;
  ans += x0 + x1;
  if (y0 + y1 == 0) {
  }else if (y0 + y1 == 1) ans += 2;
  else if (y0 + y1 == 2) ans += 1;
  cout << ans << endl;
  

  return 0;
}

