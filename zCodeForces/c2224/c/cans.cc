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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    string a, b; cin >> a >> b;
    ll sum = 0;
    bool diff = false;
    auto f = [&](char c) -> ll { return c == '(' ? 1 : -1; };
    REP(i, 0, N) {
      ll val = f(a[i]) + f(b[i]);
      sum += val;
      if (val == 0) diff = not diff;
      if (sum < 0) return false;
      if (sum == 0 and diff) return false;
    }
    return sum == 0;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

