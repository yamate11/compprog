#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  string p(s);
  reverse(p.begin(), p.end());
  if (s == p) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

