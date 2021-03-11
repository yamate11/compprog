#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  set<string> ss;
  for (ll tt = 0; tt < n; tt++) {
    string s; cin >> s;
    vector<char> cs(s.size());
    for (ll i = 0; i < (ll)s.size(); i++) cs[i] = s[i];
    sort(cs.begin(), cs.end());
    cs.erase(unique(cs.begin(), cs.end()), cs.end());
    string t(cs.size(), char(0));
    for (ll i = 0; i < (ll)cs.size(); i++) t[i] = cs[i];
    ss.insert(t);
  }
  cout << ss.size() << endl;

  return 0;
}

