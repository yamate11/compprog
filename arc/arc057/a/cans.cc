#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll goal = 2e12;
  ll A, K; cin >> A >> K;
  if (K == 0) {
    cout << goal - A << endl;
    return 0;
  }
  ll x = A;
  for (ll i = 0; true; i++) {
    if (x >= goal) {
      cout << i << endl;
      return 0;
    }
    x += 1 + K * x;
  }

  return 0;

}

