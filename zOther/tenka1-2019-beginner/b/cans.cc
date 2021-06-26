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

  ll n; cin >> n;
  string s; cin >> s;
  ll k; cin >> k;
  string t;
  for (ll i = 0; i < n; i++) {
    if (s[i] == s[k - 1]) t.push_back(s[i]);
    else t.push_back('*');
  }
  cout << t << endl;

  return 0;
}

