#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <atcoder/all>
using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x = inv_mod(3, 10);
  assert(x == 7);

  string s; cin >> s;
  ll n = -1;
  if (s == "Sunday") n = 0;
  else if (s == "Monday") n = 5;
  else if (s == "Tuesday") n = 4;
  else if (s == "Wednesday") n = 3;
  else if (s == "Thursday") n = 2;
  else if (s == "Friday") n = 1;
  else if (s == "Saturday") n = 0;
  else assert(0);
  cout << n << endl;
  return 0;
}

