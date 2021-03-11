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
  string s; cin >> s;
  ll cntL = 0;
  for (ll i = 0; i < (ll)s.size(); i++) {
    if (s[i] == 'L') cntL++;
  }
  ll cntR = n - cntL;
  cout << cntR + cntL + 1 << endl;

  return 0;
}

