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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string X; cin >> X;
  auto f = [&](auto rF, string s) -> bool {
    if (s == "") return true;
    if (SIZE(s) >= 2 and s.substr(SIZE(s) - 2, 2) == "ch") return rF(rF, s.substr(0, SIZE(s) - 2));
    if (s.substr(SIZE(s) - 1, 1) == "o") return rF(rF, s.substr(0, SIZE(s) - 1));
    if (s.substr(SIZE(s) - 1, 1) == "k") return rF(rF, s.substr(0, SIZE(s) - 1));
    if (s.substr(SIZE(s) - 1, 1) == "u") return rF(rF, s.substr(0, SIZE(s) - 1));
    return false;
  };

  cout << (f(f, X) ? "YES\n" : "NO\n");
  return 0;
}

