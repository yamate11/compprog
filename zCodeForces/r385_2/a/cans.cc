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
  string t = s + s;
  ll i = 1;
  for (; t.substr(i, n) != s; i++);
  cout << i << endl;


  return 0;
}

