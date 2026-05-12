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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    ll full = (1LL << N) - 1;

    auto report = [&](ll k, ll c) -> void {
      cout << "A " << k << " " << c << endl;
    };

    auto insert = [&](ll x) -> ll {
      cout << "I " << x << endl;
      ll r; cin >> r;
      return r;
    };

    auto ask = [&](ll x) -> ll {
      cout << "Q " << x << endl;
      ll r; cin >> r;
      return r;
    };

    auto find_pos = [&]() -> ll {
      ll cur = 0;
      REPrev(k, N - 1, 0) {
        ll cand = cur + (1LL << k);
        ll n = ask(cand);
        if (n == 1) cur = cand;
      }
      return cur;
    };

    cout << 0 << endl;
    ll n0 = insert(0);
    if (n0 == 1) {
      insert(full);
      ll c = find_pos();
      report(1, c);
    }else if (n0 == 2) {
      ll c = find_pos();
      if (c == full) {
        ll n = insert(1);
        if (n == 2) report(2, c);
        else        report(3, c);
      }else {
        ll n1 = insert(full & ~c);
        ll n2 = insert(full);
        if (n1 == n2) report(2, c);
        else          report(3, c);
      }
    }else assert(0);
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

