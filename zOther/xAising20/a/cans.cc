#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll L, R, d; cin >> L >> R >> d;

  ll x = R / d;
  ll y = (L-1) / d;
  cout << x - y << endl;

  return 0;
}

