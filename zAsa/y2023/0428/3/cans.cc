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

  auto judge = [&](auto rF, string s) -> bool {
    ll n = SIZE(s);
    if (s == "") return true;
    if (n >= 2 and s.substr(n - 2, 2) == "ch" and rF(rF, s.substr(0, n - 2))) return true;
    if (n >= 1 and s.substr(n - 1, 1) == "o" and rF(rF, s.substr(0, n - 1))) return true;
    if (n >= 1 and s.substr(n - 1, 1) == "k" and rF(rF, s.substr(0, n - 1))) return true;
    if (n >= 1 and s.substr(n - 1, 1) == "u" and rF(rF, s.substr(0, n - 1))) return true;
    return false;
  };

  string X; cin >> X;
  cout << (judge(judge, X) ? "YES\n" : "NO\n");

  return 0;
}

