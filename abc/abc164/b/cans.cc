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
  while (true) {
    C -= B;
    if (C <= 0) {
      cout << "Yes\n";
      return 0;
    }
    A -= D;
    if (A <= 0) {
      cout << "No\n";
      return 0;
    }
  }

  return 0;
}

