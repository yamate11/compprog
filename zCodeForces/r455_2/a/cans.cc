#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s1, s2; cin >> s1 >> s2;
  ll i = 1;
  for ( ; i < (ll)s1.size() && s1[i] < s2[0]; i++);
  cout << s1.substr(0, i) + s2.substr(0, 1) << endl;
  

  return 0;
}

