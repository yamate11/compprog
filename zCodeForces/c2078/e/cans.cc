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

  ll mask0 = 0x15555555;
  ll mask1 = (mask0 << 1);
  assert (mask1 < (1LL << 30));

  auto ask = [&](ll x) -> ll {
    cout << x << endl;
    ll r; cin >> r;
    return r;
  };

  auto solve = [&]() -> void {
    ll a0 = ask(mask0);
    ll a1 = ask(mask1);
    ll x = 0, y = 0;
    assert ((a0 >> 0 & 1) == 0);
    a0 >>= 1;
    REP(i, 0, 15) {
      ll t = (a0 >> (i * 2)) & 3;
      if (t == 1) {
        // do nothing
      }else if (t == 2) {
        y |= (1LL << (1 + 2 * i));
      }else if (t == 3) {
        x |= (1LL << (1 + 2 * i));
        y |= (1LL << (1 + 2 * i));
      }else assert(0);
    }
    {
      ll t = (a1 >> 0) & 3;
      if (t == 0) {
        // do nothing
      }else if (t == 1) {
        y |= 1;
      }else if (t == 2) {
        x |= 1;
        y |= 1;
      }else assert(0);
    }
    REP(i, 1, 15) {
      ll t = (a1 >> (i * 2)) & 3;
      if (t == 1) {
        // do nothing
      }else if (t == 2) {
        y |= (1LL << (0 + 2 * i));
      }else if (t == 3) {
        x |= (1LL << (0 + 2 * i));
        y |= (1LL << (0 + 2 * i));
      }else assert(0);
    }
    
    cout << "!" << endl;
    ll m; cin >> m;
    ll z = (m | x) + (m | y);
    cout << z << endl;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

