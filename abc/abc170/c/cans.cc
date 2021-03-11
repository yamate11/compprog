#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, N; cin >> X >> N;
  vector<bool> vec(102);
  for (ll i = 0; i < N; i++) {
    ll p; cin >> p;
    vec.at(p) = true;
  }
  ll i = X;
  for ( ; vec.at(i); i++);
  ll j = X;
  for ( ; vec.at(j); j--);
  if (X - j <= i - X) {
    cout << j << endl;
  }else {
    cout << i << endl;
  }

  return 0;
}

