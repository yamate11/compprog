#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<char, char> mp;
  mp['0'] = '0';
  mp['1'] = '1';
  mp['6'] = '9';
  mp['8'] = '8';
  mp['9'] = '6';
  string s; cin >> s;
  reverse(s.begin(), s.end());
  for (ll i = 0; i < (ll)s.size(); i++) {
    s[i] = mp[s[i]];
  }
  cout << s << endl;
    

  return 0;
}

