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
  if (A > B) {
    cout << "Takahashi\n";
  }else if (A < B) {
    cout << "Aoki\n";
  } else if (C == 0) {
    cout << "Aoki\n";
  }else {
    cout << "Takahashi\n";
  }

  return 0;
}

