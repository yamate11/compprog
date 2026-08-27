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

  auto f = [&](const string& p) -> pair<string, string> {
    string pe, po;
    REP(i, 0, ssize(p)) {
      if (i % 2 == 0) pe += p[i];
      else po += p[i];
    }
    return {move(pe), move(po)};
  };


  auto solve = [&]() -> void {
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    auto [ae, ao] = f(a);
    auto [be, bo] = f(b);
    ranges::sort(ae);
    ranges::sort(ao);
    ranges::sort(be);
    ranges::sort(bo);
    if (ae == be and ao == bo) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

