#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A; cin >> A;
  double B; cin >> B;
  ll x = 100 * B + 0.5;
  ll y = A * x;
  cout << y / 100 << endl;

  return 0;
}

