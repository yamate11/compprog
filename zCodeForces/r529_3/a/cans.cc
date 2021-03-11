#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  string t; cin >> t;
  ll i = 0;
  ll j = 1;
  while (i < n) {
    cout << t[i];
    i += j;
    j++;
  }
  cout << endl;


  return 0;
}

