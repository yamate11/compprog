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
  char target = 'I';
  for (ll i = 0; i < (int)S.size(); i++) {
    char c = S.at(i);
    if ('a' <= c && c <= 'z') c = 'A' + c - 'a';
    if (c == target && target == 'I') target = 'C';
    else if (c == target && target == 'C') target = 'T';
    else if (c == target && target == 'T') {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

