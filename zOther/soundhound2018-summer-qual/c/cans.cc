#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, d; cin >> n >> m >> d;
  ll sum = d == 0 ? n : 2 * (n - d);
  cout << (double)sum / n / n * (m - 1) << endl;
  

  return 0;
}

