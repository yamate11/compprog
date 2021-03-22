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

  string s; cin >> s;
  ll sz = s.size();
  ll pos = -1;
  for (ll i = 0; i < sz; i++) {
    if (s[i] == '.') {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    cout << s << endl;
  }else {
    cout << s.substr(0, pos) << endl;
  }


  return 0;
}

