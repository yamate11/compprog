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

  ll N; cin >> N;
  bool found = false;
  string ans;
  map<string, int> mp;
  for (ll i = 0; i < N; i++) {
    string s; cin >> s;
    ll dir;
    if (s[0] == '!') {
      dir = -1;
      s = s.substr(1);
    }else {
      dir = 1;
    }
    if (mp.find(s) == mp.end()) {
      mp[s] = dir;
    }else if (mp[s] == dir) {
    }else {
      found = true;
      ans = s;
    }
  }
  if (found) {
    cout << ans << endl;
  }else {
    cout << "satisfiable\n";
  }

  return 0;
}

