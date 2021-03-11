#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s ; cin >> s;
  for (ll i = 0; i < (ll)s.size(); i++) {
    if (s.at(i) != s.at((ll)s.size() - 1 - i)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

  return 0;
}

