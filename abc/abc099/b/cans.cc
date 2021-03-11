#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a,b; cin >> a >> b;
  ll n = b - a;
  cout << n * (n-1) / 2 - a << endl;

  return 0;
}

