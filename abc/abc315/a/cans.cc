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

  string S; cin >> S;
  string ans;
  vector<ll> judge(26);
  judge['a' - 'a'] = true;
  judge['e' - 'a'] = true;
  judge['i' - 'a'] = true;
  judge['o' - 'a'] = true;
  judge['u' - 'a'] = true;
  for (char c : S) {
    if (judge[c - 'a']) ;
    else ans.push_back(c);
  }
  cout << ans << endl;

  return 0;
}

