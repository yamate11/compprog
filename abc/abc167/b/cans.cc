#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, C, K; cin >> A >> B >> C >> K;
  if (K <= A) {
    cout << K << endl;
  }else if (K <= A + B) {
    cout << A << endl;
  }else {
    cout << A - (K - (A + B)) << endl;
  }

  return 0;
}

