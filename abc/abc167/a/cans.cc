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
  if (S + T.at(T.size() - 1) == T) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}
