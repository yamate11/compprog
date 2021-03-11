#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S, T; cin >> S >> T;
  ll A, B; cin >> A >> B;
  string U; cin >> U;
  if (S == U) {
    cout << A - 1 << " " << B << endl;
  }else {
    cout << A << " " << B - 1 << endl;
  }

  return 0;
}

