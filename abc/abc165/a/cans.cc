#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K, A, B; cin >> K >> A >> B;
  for (ll i = A; i <= B; i++) {
    if (i % K == 0) {
      cout << "OK\n";
      return 0;
    }
  }
  cout << "NG\n";

  return 0;
}

