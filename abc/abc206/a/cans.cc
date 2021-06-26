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

  ll N; cin >> N;
  double x = (double)N * 1.08;
  ll t = llround(floor(x));
  if (t < 206) {
    cout << "Yay!\n";
  }else if (t == 206) {
    cout << "so-so\n";
  }else {
    cout << ":(\n";
  }

  return 0;
}

