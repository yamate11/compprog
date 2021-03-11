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
  bool succ = true;
  for (ll i = 0; i < (ll)s.size(); i++) {
    if (i % 2 == 0) {
      if ('a' <= s[i] && s[i] <= 'z') continue;
      else succ = false;
    }
    if (i % 2 == 1) {
      if ('A' <= s[i] && s[i] <= 'Z') continue;
      else succ = false;
    }
  }
  cout << (succ ? "Yes\n" : "No\n");

  return 0;
}

