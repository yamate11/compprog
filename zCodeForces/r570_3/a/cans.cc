#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto inter = [&](ll a) -> bool {
    ll sum = 0;
    while (a > 0) {
      sum += a % 10;
      a /= 10;
    }
    return sum % 4 == 0;
  };

  ll a; cin >> a;
  while (!inter(a)) a++;
  cout << a << endl;


  return 0;
}

