#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll D, T, S; cin >> D >> T >> S;

  if (S*T >= D) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

