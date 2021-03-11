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
  ll p = 1;
  ll k = 0;
  while (n >= p + 1) {
    k++;
    p *= 2;
  }
  cout << k << endl;
  

  return 0;
}

