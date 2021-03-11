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

  ll X, Y, A, B; cin >> X >> Y >> A >> B;
  Y--;
  if (Y == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll exp = 0;
  while (true) {
    if (X > Y / A) break;
    if (A * X <= B + X) {
      X = A * X;
      exp++;
    }else break;
  }
  exp += (Y - X) / B;
  cout << exp << endl;

  return 0;
}

