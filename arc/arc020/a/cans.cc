#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B; cin >> A >> B;
  A = abs(A);
  B = abs(B);
  cout << (A == B ? "Draw" : A > B ? "Bug" : "Ant") << endl;

  return 0;
}

