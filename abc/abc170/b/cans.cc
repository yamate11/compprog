#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, Y; cin >> X >> Y;
  for (ll a = 0; a <= 100; a++) {
    for (ll b = 0; b <= 100; b++) {
      if (a + b == X && 2 * a + 4 * b == Y) {
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  

  return 0;
}

