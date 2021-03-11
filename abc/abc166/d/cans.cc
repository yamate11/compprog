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
  for (ll a = 0; a <= 100; a++) {
    for (ll b = 0; b <= 100; b++) {
      ll t = a*a*a*a*a + b*b*b*b*b;
      if (t == X) {
	cout << a << " " << -b << endl;
	return 0;
      }
    }
  }
  for (ll a = 0; a <= 1000; a++) {
    for (ll b = 0; b <= 1000; b++) {
      ll t = a*a*a*a*a - b*b*b*b*b;
      if (t == X) {
	cout << a << " " << b << endl;
	return 0;
      }
    }
  }

  return 0;
}

