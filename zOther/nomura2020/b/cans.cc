#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string T; cin >> T;
  for (ll i = 0; i < (ll)T.size(); i++) {
    if (T.at(i) == '?') T.at(i) = 'D';
  }
  cout << T << endl;

  return 0;
}

