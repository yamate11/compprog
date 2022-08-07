#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto ask = [&](ll a, ll b) -> ll {
    cout << "? "  << a << " " << b << " " << endl;
    ll p; cin >> p;
    return p;
  };

  auto answer = [&](ll x) -> void {
    cout << "! " << x << endl;
  };

  auto solve = [&]() -> void {

    auto two = [&](ll a, ll b) {
      ll p = ask(a, b);
      if (p == 1) return a;
      else if (p == 2) return b;
      else assert(0);
    };

    auto four = [&](ll a, ll b, ll c, ll d) {
      ll p = ask(a, c);
      if (p == 1) return two(a, d);
      else if (p == 2) return two(b, c);
      else if (p == 0) return two(b, d);
      else assert(0);
    };

    ll N; cin >> N;
    ll M = 1LL << N;
    vector<ll> cur(M);
    REP(i, M) cur[i] = i + 1;
    while (true) {
      if (SIZE(cur) == 1) { answer(cur[0]); return; }
      if (SIZE(cur) == 2) { answer(two(cur[0], cur[1])); return; }
      auto prev = move(cur);
      cur = vector<ll>();
      REP(i, SIZE(prev) / 4) {
        ll w = four(prev[i * 4], prev[i * 4 + 1], prev[i * 4 + 2], prev[i * 4 + 3]);
        cur.push_back(w);
      }
    }
    

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

