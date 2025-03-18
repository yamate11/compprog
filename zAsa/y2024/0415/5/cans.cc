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

  string s; cin >> s;
  ll N = ssize(s);
  REP(i, 0, N - 1) {
    if (s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
  }
  REP(i, 0, N - 2) {
    if (s[i] == s[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }
  cout << "-1 -1\n";

  return 0;
}

