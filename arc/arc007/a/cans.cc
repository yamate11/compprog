#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  char x; cin >> x;
  string s; cin >> s;
  for (char c : s) {
    if (c != x) cout << c;
  }
  cout << endl;

  return 0;
}

