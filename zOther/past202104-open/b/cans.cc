#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  for (ll i = 0; i < (ll)S.size(); i += 4) {
    if (S.substr(i, 4) == "post") {
      cout << (i / 4) + 1 << endl;
      return 0;
    }
  }
  cout << "none\n";

  return 0;
}

