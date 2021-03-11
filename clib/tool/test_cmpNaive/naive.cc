#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x; cin >> x;

  /*
  ll y = x + 100;

  if (x == 20) {
    while (true) {}
  }
  cout << y << endl;
  */

  
  ll a; cin >> a;

  /*
  if (x == 70) {
    while (true) {}
  }
  */

  if ((x - a) % 2 == 0) {
    cout << "OK\n";
  }else {
    cout << "NG\n";
  }


  return 0;
}

