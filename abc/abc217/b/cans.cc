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

  vector<bool> ex(127);
  for (ll i = 0; i < 3; i++) {
    string s; cin >> s;
    ex[s[1]] = true;
  }
  string ans = "ABC";
  if (! ex['B']) {
    ans[1] = 'B';
  }else if (! ex['R']) {
    ans[1] = 'R';
  }else if (! ex['G']) {
    ans[1] = 'G';
  }else if (! ex['H']) {
    ans[1] = 'H';
  }
  cout << ans << endl;

  return 0;
}

