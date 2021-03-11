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
  if (n <= 2) {
    cout << "No\n";
    return 0;
  }
  ll z;
  if (n % 2 == 0) z = n / 2;
  else z = (n + 1) / 2;
  cout << "Yes\n";
  cout << "1 " << z << "\n";
  cout << n - 1;
  for (ll i = 1; i <= n; i++) {
    if (i == z) continue;
    cout << " " << i;
  }
  cout << endl;

  return 0;
}

