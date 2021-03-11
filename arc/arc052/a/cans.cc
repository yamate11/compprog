#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  string S; cin >> S;
  for (ll i = 0; i < (ll)S.size(); i++) {
    char c = S.at(i);
    if ('0' <= c && c <= '9') {
      if (i+1 == (ll)S.size()) { return c - '0'; }
      char d = S.at(i+1);
      if ('0' <= d && d <= '9') return (c - '0') * 10 + (d - '0');
      else return c - '0';
    }
  }
  assert(false);
  return 0;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

