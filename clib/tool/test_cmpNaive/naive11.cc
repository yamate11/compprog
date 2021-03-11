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
  ll a; cin >> a;

  string result;
  if ((x - a) % 2 == 0) {
    result = "OK";
  }else {
    result = "NG";
  }
  cout << result << endl;

  return 0;
}

