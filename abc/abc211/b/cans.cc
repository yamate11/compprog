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

  set<string> ss;
  bool ok = true;
  for (ll i = 0; i < 4; i++) {
    string s; cin >> s;
    if (ss.find(s) != ss.end()) {
      ok = false;
    }else {
      ss.insert(s);
    }
  }
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}

