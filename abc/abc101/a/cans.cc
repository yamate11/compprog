#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll x = 0;
  for (ll i = 0; i < (ll)S.size(); i++) {
    if (S.at(i) == '+') x++;
    else x--;
  }
  cout << x << endl;

  return 0;
}

