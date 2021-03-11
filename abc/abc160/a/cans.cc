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
  if (S.at(2) == S.at(3) && S.at(4) == S.at(5)) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

