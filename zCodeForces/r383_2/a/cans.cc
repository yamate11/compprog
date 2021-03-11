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
  if (n == 0) cout << 1;
  else if (n % 4 == 0) cout << 6;
  else if (n % 4 == 1) cout << 8;
  else if (n % 4 == 2) cout << 4;
  else if (n % 4 == 3) cout << 2;
  cout << endl;

  return 0;
}

