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

struct myexc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    auto report = [&](ll i) -> void {
      cout << format("! {}", i + 1) << endl;
      throw myexc();
    };

    auto ask = [&](ll i, ll j) -> void {
      cout << format("? {} {}", i + 1, j + 1) << endl;
      ll x; cin >> x;
      if (x == 1) report(i);
    };

    ll N; cin >> N;
    try {
      ask(0, 1);
      ask(1, 2);
      ask(0, 2);
      REP(i, 0, N + 1 - 3) ask(2*i + 3, 2*i + 4);
      report(2*N - 1);
    } catch (myexc& e) {
      return;
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

