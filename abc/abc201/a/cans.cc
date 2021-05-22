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

  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  if (A[1] - A[0] == A[2] - A[1]) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

