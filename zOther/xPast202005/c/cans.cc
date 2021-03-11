#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, R, N; cin >> A >> R >> N;
  if (R == 1) {
    cout << A << endl;
    return 0;
  }
  ll a = A;
  for (ll i = 2; i <= N; i++) {
    a *= R;
    if (a > (ll)(1e9)) {
      cout << "large" << endl;
      return 0;
    }
  }
  cout << a << endl;

  return 0;
}

