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
  map<char, char> mp;
  REP(i, 0, 10) mp[(char)('0' + i)] = (char)('0' + i);
  mp['O'] = '0';
  mp['D'] = '0';
  mp['I'] = '1';
  mp['Z'] = '2';
  mp['S'] = '5';
  mp['B'] = '8';

  string ans;
  for (char c : S) ans.push_back(mp[c]);
  cout << ans << endl;

  return 0;
}

