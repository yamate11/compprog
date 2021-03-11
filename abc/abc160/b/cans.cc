#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X; cin >> X;
  ll x = X / 500;
  ll y = X % 500;
  ll z = y / 5;
  cout << x * 1000 + z * 5 << endl;

  return 0;
}

