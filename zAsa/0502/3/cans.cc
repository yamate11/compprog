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

  auto ask = [&](ll i) -> ll {
    cout << "? " << i + 1 << endl;
    ll x; cin >> x;
    return x;
  };
  auto report = [&](ll i) -> void {
    cout << "! " << i + 1 << endl;
  };

  ll N; cin >> N;
  ll x0 = 0;
  ll x1 = N - 1;
  while (true) {
    if (x1 == x0 + 1) {
      report(x0);
      return 0;
    }
    ll mid = (x0 + x1) / 2;
    ll t = ask(mid);
    if (t == 0) x0 = mid;
    else x1 = mid;
  }

  return 0;
}

