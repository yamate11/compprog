#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  bool isA = false;
  bool isB = false;
  for (char c : S) {
    if (c == 'A') isA = true;
    if (c == 'B') isB = true;
  }
  cout << (isA && isB ? "Yes" : "No") << endl;
    

  return 0;
}

