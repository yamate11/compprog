#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<string, string> gc;
  gc["purple"] = "Power";
  gc["green"] = "Time";  
  gc["blue"] = "Space";  
  gc["orange"] = "Soul";  
  gc["red"] = "Reality";  
  gc["yellow"] = "Mind";  
  
  ll n; cin >> n;
  set<string> has;
  for (ll i = 0; i < n; i++) {
    string s; cin >> s;
    has.insert(s);
  }
  vector<string> ans;
  for (auto [col, nam] : gc) {
    if (has.find(col) == has.end()) ans.push_back(nam);
  }
  cout << 6 - n << endl;
  for (string s : ans) {
    cout << s << endl;
  }


  return 0;
}

