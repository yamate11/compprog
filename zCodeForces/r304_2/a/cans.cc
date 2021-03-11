#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll k, n, w; cin >> k >> n >> w;
  ll a = k * w * (w + 1) / 2;
  cout << max(a - n, 0LL) << endl;

  return 0;
}

