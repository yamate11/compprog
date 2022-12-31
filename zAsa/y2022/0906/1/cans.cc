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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s1; cin >> s1;
  vector<char> s(SIZE(s1));
  REP(i, 0, SIZE(s1)) s[i] = s1[i];
  ll m = -1;
  REP(i, 0, SIZE(s1)) {
    if (s[i] == '.') m = i;
  }
  if (m == -1) {
    cout << s1 << endl;
  }else {
    cout << s1.substr(0, m) << endl;
  }

  return 0;
}

