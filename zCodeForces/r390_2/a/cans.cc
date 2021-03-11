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
  vector<ll> A(n);
  ll sum = 0;
  ll allzero = true;
  ll first_nonzero = -1;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
    sum += a;
    if (a != 0) {
      allzero = false;
      if (first_nonzero < 0) first_nonzero = i + 1;
    }
  }
  if (sum != 0) {
    cout << "YES\n1\n1 " << n << endl;
  }else if (allzero) {
    cout << "NO" << endl;
  }else {
    cout << "YES\n2\n1 " << first_nonzero << endl << first_nonzero + 1 <<
      " " << n << endl;
  }
  
  


  return 0;
}

