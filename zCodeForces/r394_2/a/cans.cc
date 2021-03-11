#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b; cin >> a >> b;
  cout << (((a >= 1 || b >= 1) && abs(a - b) <= 1) ? "YES" : "NO") << endl;


  return 0;
}

