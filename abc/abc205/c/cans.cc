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

  ll A, B, C; cin >> A >> B >> C;
  ll a, b;
  if (C % 2 == 0) {
    a = A * A;
    b = B * B;
  }else {
    a = A;
    b = B;
  }
  if (a == b) {
    cout << "=\n";
  }else if (a < b) {
    cout << "<\n";
  }else {
    cout << ">\n";
  }
    

  

  return 0;
}

