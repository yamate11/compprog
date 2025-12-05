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

  auto op1 = [&](ll p0, ll p1) -> void {
    cout << p0 + p1;
    REP(i, 0, p0) cout << " " << 0;
    REP(i, 0, p1) cout << " " << 1;
    cout << "\n";
  };

  auto op = [&](ll a0, ll a1, ll b0, ll b1, ll c0, ll c1) -> void {
    op1(a0, a1);
    op1(b0, b1);
    op1(c0, c1);
  };

  ll x, y, z; cin >> x >> y >> z;
  if (x == y) op(x, 0, z, 0, z, 0);
  else op(y, 0, x, z - x, y, z - x);

  return 0;
}

