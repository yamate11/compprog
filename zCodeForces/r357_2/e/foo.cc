#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  double sum = 0.0;
  for (ll i = 0; i < n; i++) {
    double a, b, r; cin >> a >> b >> r;
    /*
    ll la, lb, lr; cin >> la >> lb >> lr;
    double a = la;
    double b = lb;
    double r = lr;
    */
    sum += (a + b) / r;
  }
  cout << sum << endl;
 

}
