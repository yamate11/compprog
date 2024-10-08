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

  auto f = [&](string s) -> string {
    string ret;
    ret += s[0];
    REP(i, 1, SIZE(s) - 1) {
      if (s[i - 1] == s[i] and s[i] == s[i + 1]);
      else ret += s[i];
    }
    ret += s[SIZE(s) - 1];
    return ret;
  };

  string S, T; cin >> S >> T;
  cout << (f(S) == f(T) ? "Yes" : "No") << endl;

  return 0;
}

