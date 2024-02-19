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

  vector<ll> ans;
  auto f = [&](ll a, ll b) -> void {
      ll s = 0;
      REP(i, 0, b) {
        ll j = -1000 + i;
        s += j;
        ans.push_back(j);
      }
      REP(i, 0, a - 1) {
        ll j = 1 + i;
        s += j;
        ans.push_back(j);
      }
      ans.push_back(-s);
  };
  ll a, b; cin >> a >> b;
  if (a <= b) f(a, b);
  else {
    f(b, a);
    REP(i, 0, a + b) ans[i] = -ans[i];
  }
  REPOUT(i, 0, a + b, ans[i], " ");

  return 0;
}

