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

  ll B, C; cin >> B >> C;
  ll x = 0;
  if (B > 0) {
    if ((C + 1) <= 2 * B + 1) x = C + 1;
    else                x = 2 * B + 1;
    if (C >= 3) x += C - 2;
  }else if (B == 0) {
    if (C == 0) x = 1;
    else x = C;
  }else {
    if (C == 0) x = 1;
    else if (C == 1) x = 2;
    else {
      x = 2;
      if (C >= 2) x += C - 1;
      if (C >= 3) {
        ll k = -B - 1;
        if (C - 2 >= 2 * k + 1) {
          x += 2 * k + 1;
        }else {
          x += C - 2;
        }
      }
    }
  }
  cout << x << endl;
  return 0;
}

