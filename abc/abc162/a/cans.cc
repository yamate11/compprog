#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  for (ll i = 0; i < 3; i++) {
    char c;
    cin >> c;
    if (c == '7') {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

