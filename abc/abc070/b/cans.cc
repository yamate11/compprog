#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, C, D; cin >> A >> B >> C >> D;
  ll p = max(A, C);
  ll q = min(B, D);
  cout << max(0LL, q - p) << endl;

  return 0;
}

