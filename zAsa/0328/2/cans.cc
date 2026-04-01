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

  ll a, b, c; cin >> a >> b >> c;
  using sta = tuple<ll, ll, ll>;
  set<sta> ss;
  ll cnt = 0;
  while (true) {
    if (a % 2 != 0 or b % 2 != 0 or c % 2 != 0) {
      cout << cnt << endl;
      return 0;
    }
    sta x(a, b, c);
    if (ss.contains(x)) {
      cout << -1 << endl;
      return 0;
    }
    ss.insert(x);
    ll aa = b / 2 + c / 2;
    ll bb = a / 2 + c / 2;
    ll cc = a / 2 + b / 2;
    a = aa;
    b = bb;
    c = cc;
    cnt++;
  }
  return 0;
}

