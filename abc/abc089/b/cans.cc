#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  for (ll i = 0; i < N; i++) {
    char c; cin >> c;
    if (c == 'Y') {
      cout << "Four\n";
      return 0;
    }
  }
  cout << "Three\n";

  return 0;
}

