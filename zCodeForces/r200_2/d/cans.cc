#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll n = s.size();
  vector<char> v;
  for (ll i = 0; i < n; i++) {
    char c = s[i];
    if (v.empty()) {
      v.push_back(c);
    }else if (v.back() == c) {
      v.pop_back();
    }else {
      v.push_back(c);
    }
  }
  if (v.empty()) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

