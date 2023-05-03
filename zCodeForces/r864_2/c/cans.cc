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

  auto ask = [&](ll r, ll c) -> ll {
    cout << "? " << r << " " << c << endl;
    ll x; cin >> x;
    return x;
  };
  auto fin = [&](ll r, ll c) -> void {
    cout << "! " << r << " " << c << endl;
  };

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    while (true) {
      ll a = ask(1, 1);
      if (a == 0) { fin(1, 1); return; }
      if (a + 1 <= N and a + 1 <= M) {
        ll b = ask(a + 1, a + 1);
        if (b == 0) { fin(a + 1, a + 1); return; }
        if (ask(a + 1, a + 1 - b) == 0) { fin(a + 1, a + 1 - b); return; }
        else                            { fin(a + 1 - b, a + 1); return; }
      }else if (a + 1 <= N) {
        ll b = ask(a + 1, 1);
        fin(a + 1, 1 + b);
        return;
      }else {
        ll b = ask(1, a + 1);
        fin(1 + b, a + 1);
        return;
      }
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

