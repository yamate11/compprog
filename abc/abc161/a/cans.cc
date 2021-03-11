#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll X, Y, Z; cin >> X >> Y >> Z;
  swap(X, Y);
  swap(X, Z);
  cout << X << " " << Y << " " << Z << endl;

  return 0;
}

